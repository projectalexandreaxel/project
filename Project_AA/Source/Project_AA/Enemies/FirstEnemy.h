// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "FirstEnemy.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_AA_API AFirstEnemy : public AEnemy
{
	GENERATED_BODY()

public:
	AFirstEnemy();

private:
	virtual void SetupMesh() override;
	virtual void SetupPawnSensingComponent() override;

	UFUNCTION() 
	void OnSeePawn(APawn* SeenPawn);
};
