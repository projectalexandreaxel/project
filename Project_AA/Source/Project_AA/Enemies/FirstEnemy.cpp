// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstEnemy.h"
#include "Components/CapsuleComponent.h"
#include "AIController.h"
#include "../DefaultCharacter.h"

AFirstEnemy::AFirstEnemy()
{
    GetCapsuleComponent()->InitCapsuleSize(50.f, 50.f);

    SetupMesh();

    SetupPawnSensingComponent();
}

void AFirstEnemy::SetupMesh()
{
    // TODO Change
    static ConstructorHelpers::FObjectFinder<USkeletalMesh>DefaultSkeletalMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequin_UE4/Meshes/SK_Mannequin.SK_Mannequin'"));
	GetMesh()->SetSkeletalMeshAsset(DefaultSkeletalMesh.Object);

	// Adjust Mesh direction and rotation with player's capsule
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -45.f), FRotator(0.f, -90.f, 0.f));
}

void AFirstEnemy::SetupPawnSensingComponent()
{
    PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComponent"));
    PawnSensingComponent->HearingThreshold = 0.f;
    PawnSensingComponent->LOSHearingThreshold = 0.f;
    PawnSensingComponent->OnSeePawn.AddDynamic(this, &AFirstEnemy::OnSeePawn);
}

void AFirstEnemy::OnSeePawn(APawn* SeenPawn)
{
    ADefaultCharacter* SeenCharacter = Cast<ADefaultCharacter>(SeenPawn);

    if(SeenCharacter)
    {
        AAIController* EnemyController = Cast<AAIController>(GetController());

        if(EnemyController) {
            EnemyController->MoveToActor(SeenPawn);
        }
    }
}