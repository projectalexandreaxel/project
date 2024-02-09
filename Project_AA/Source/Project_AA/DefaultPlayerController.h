// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DefaultPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_AA_API ADefaultPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

private:
	// Axis mapping
	void MoveForwardBackward(float Value);
	void MoveRightLeft(float Value);
	void TurnRightLeft(float Value);
	void LookUpDown(float Value);

	// Action mapping
	void Jump();
	void Interact();
};
