// Copyright Epic Games, Inc. All Rights Reserved.

#include "DefaultCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Interactables/InteractableInterface.h"
#include "InputActionValue.h"
#include "Weapons/Sword.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ADefaultCharacter

ADefaultCharacter::ADefaultCharacter()
{
	CapsuleHalfHeight = 90.f;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, CapsuleHalfHeight);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	SetupCamera();

	SetupMesh();

	SetupStatus();

	// TODO Use a default CharacterMovement class instead
	SetupCharacterMovement();

	SetupInteractSphere();

	EquippedWeapon = CreateDefaultSubobject<ASword>(TEXT("EquippedWeapon"));
	EquippedWeapon->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void ADefaultCharacter::SetupCamera()
{
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}

void ADefaultCharacter::SetupCharacterMovement()
{
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = MaxSpeed;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
}

void ADefaultCharacter::SetupMesh()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>DefaultSkeletalMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequin_UE4/Meshes/SK_Mannequin.SK_Mannequin'"));
	GetMesh()->SetSkeletalMeshAsset(DefaultSkeletalMesh.Object);

	const ConstructorHelpers::FObjectFinder<UAnimBlueprint> PlayerAnimationBlueprint(TEXT("/Script/Engine.AnimBlueprint'/Game/Characters/Mannequins/Animations/ABP_Manny.ABP_Manny'"));
	GetMesh()->SetAnimInstanceClass(PlayerAnimationBlueprint.Object->GeneratedClass);

	// Adjust Mesh direction and rotation with player's capsule
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -CapsuleHalfHeight/2), FRotator(0.f, -90.f, 0.f));
}

void ADefaultCharacter::SetupStatus()
{
	MaximumHealth = 500;
	MaximumMagic = 500;
	MaximumStamina = 50;
	MaxSpeed = 500.f;

	CurrentHealth = MaximumHealth;
	CurrentMagic = MaximumMagic;
	CurrentStamina = MaximumStamina;

	Shield = 0;
	Level = 0;
}

void ADefaultCharacter::SetupInteractSphere()
{
	InteractSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractSphere"));
	InteractSphere->SetupAttachment(RootComponent);
	InteractSphere->SetSphereRadius(90.f);
}

void ADefaultCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	auto PlayerController = Cast<APlayerController>(Controller);

	if (PlayerController)
	{
    	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
    	{
        	Subsystem->AddMappingContext(DefaultMappingContext, 0);
    	}
	}
}

void ADefaultCharacter::MoveForwardBackward(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if ( GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling() )
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ADefaultCharacter::MoveRightLeft(float Value)
{
    if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if ( GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling() )
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void ADefaultCharacter::TurnRightLeft(float Value)
{
	if ( Controller != NULL)
	{
		AddControllerYawInput(Value);
	}
}

void ADefaultCharacter::LookUpDown(float Value)
{
	if ( Controller != NULL)
	{
		AddControllerPitchInput(Value);
	}
}

void ADefaultCharacter::Interact()
{
	if (Controller != NULL)
	{
		TArray<AActor*> OverlappingActors;
		InteractSphere->GetOverlappingActors(OverlappingActors);
        
        for (AActor* Actor : OverlappingActors)
        {
			IInteractableInterface* InteractableActor = Cast<IInteractableInterface>(Actor);
    		if(InteractableActor)
    		{
        		InteractableActor->Interact();
    		}
        }
	}
}

void ADefaultCharacter::Attack()
{
	if (EquippedWeapon)
	{
		EquippedWeapon->Attack();
	}
}

void ADefaultCharacter::OnStartSprint()
{
	if ( GetCharacterMovement()->IsMovingOnGround() )
		{
			GetCharacterMovement()->MaxWalkSpeed = MaxSpeed + 200.f;
		}
}

void ADefaultCharacter::OnEndSprint()
{
	if ( GetCharacterMovement()->IsMovingOnGround() )
		{
			GetCharacterMovement()->MaxWalkSpeed = MaxSpeed;
		}
}