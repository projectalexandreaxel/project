// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include <Components/SphereComponent.h>
#include "DefaultCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Capsule, meta = (AllowPrivateAccess = "true"))
	float CapsuleHalfHeight;

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere)
	class USphereComponent* InteractSphere;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status, meta = (AllowPrivateAccess = "true"))
	int32 MaximumHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status, meta = (AllowPrivateAccess = "true"))
	int32 CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status, meta = (AllowPrivateAccess = "true"))
	int32 Shield;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status, meta = (AllowPrivateAccess = "true"))
	int32 MaximumMagic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status, meta = (AllowPrivateAccess = "true"))
	int32 CurrentMagic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status, meta = (AllowPrivateAccess = "true"))
	int32 MaximumStamina;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status, meta = (AllowPrivateAccess = "true"))
	int32 CurrentStamina;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status, meta = (AllowPrivateAccess = "true"))
	int32 Level;

public:
	ADefaultCharacter();

	virtual void BeginPlay() override;
	
public:
    void MoveForwardBackward(float Value);
    void MoveRightLeft(float Value);
    void TurnRightLeft(float Value);
	void LookUpDown(float Value);

	void Interact();
private:
	void SetupCharacterMovement();
	void SetupCamera();
	void SetupMesh();
	void SetupStatus();
	void SetupInteractSphere();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

