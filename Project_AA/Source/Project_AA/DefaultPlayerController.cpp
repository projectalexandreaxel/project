// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DefaultCharacter.h"

void ADefaultPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    // Moving
    InputComponent->BindAxis("MoveForwardBackward", this, &ADefaultPlayerController::MoveForwardBackward);
    InputComponent->BindAxis("MoveRightLeft", this, &ADefaultPlayerController::MoveRightLeft);
    InputComponent->BindAxis("TurnRightLeft", this, &ADefaultPlayerController::TurnRightLeft);
    InputComponent->BindAxis("LookUpDown", this, &ADefaultPlayerController::LookUpDown);

    InputComponent->BindAction("Jump", IE_Pressed, this, &ADefaultPlayerController::Jump);
    InputComponent->BindAction("Interact", IE_Pressed, this, &ADefaultPlayerController::Interact);
}

void ADefaultPlayerController::MoveForwardBackward(float Value) {
    ADefaultCharacter* ControlledCharacter = Cast<ADefaultCharacter>(GetPawn());

    if (ControlledCharacter)
    {
        ControlledCharacter->MoveForwardBackward(Value);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Controlled Pawn is not of type ADefaultCharacter"));
    }
}

void ADefaultPlayerController::MoveRightLeft(float Value) {
    ADefaultCharacter* ControlledCharacter = Cast<ADefaultCharacter>(GetPawn());

    if (ControlledCharacter)
    {
        ControlledCharacter->MoveRightLeft(Value);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Controlled Character is not of type ADefaultCharacter"));
    }
}

void ADefaultPlayerController::TurnRightLeft(float Value) {
    ADefaultCharacter* ControlledCharacter = Cast<ADefaultCharacter>(GetPawn());

    if (ControlledCharacter)
    {
        ControlledCharacter->TurnRightLeft(Value);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Controlled Character is not of type ADefaultCharacter"));
    }
}

void ADefaultPlayerController::LookUpDown(float Value) {
    ADefaultCharacter* ControlledCharacter = Cast<ADefaultCharacter>(GetPawn());

    if (ControlledCharacter)
    {
        ControlledCharacter->LookUpDown(Value);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Controlled Character is not of type ADefaultCharacter"));
    }
}

void ADefaultPlayerController::Jump() {
    ADefaultCharacter* ControlledCharacter = Cast<ADefaultCharacter>(GetPawn());

    if (ControlledCharacter)
    {
        ControlledCharacter->Jump();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Controlled Character is not of type ADefaultCharacter"));
    }
}

void ADefaultPlayerController::Interact() {
    ADefaultCharacter* ControlledCharacter = Cast<ADefaultCharacter>(GetPawn());

    if (ControlledCharacter)
    {
        ControlledCharacter->Interact();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Controlled Character is not of type ADefaultCharacter"));
    }
}