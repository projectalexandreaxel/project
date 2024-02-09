// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/PawnSensingComponent.h"
#include "Enemy.generated.h"

UCLASS(Abstract, Blueprintable)
class PROJECT_AA_API AEnemy : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	UPawnSensingComponent* PawnSensingComponent;

private:
	virtual void SetupMesh() PURE_VIRTUAL(AEnemy::SetupMesh,);
	virtual void SetupPawnSensingComponent() PURE_VIRTUAL(AEnemy::SetupPawnSensingComponent,);
};
