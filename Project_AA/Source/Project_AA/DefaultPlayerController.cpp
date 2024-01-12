// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultPlayerController.h"
#include "DefaultCharacter.h"

void ADefaultPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    // Moving
    InputComponent->BindAxis("MoveForward", this, &ADefaultPlayerController::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &ADefaultPlayerController::MoveRight);

}

void ADefaultPlayerController::MoveForward(float Value) {
    ADefaultCharacter* ControlledCharacter = Cast<ADefaultCharacter>(GetPawn());

    if (ControlledCharacter)
    {
        ControlledCharacter->MoveForward(Value);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Controlled Pawn is not of type ADefaultCharacter"));
    }
}

void ADefaultPlayerController::MoveRight(float Value) {
    ADefaultCharacter* ControlledCharacter = Cast<ADefaultCharacter>(GetPawn());

    if (ControlledCharacter)
    {
        ControlledCharacter->MoveRight(Value);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Controlled Character is not of type ADefaultCharacter"));
    }
}