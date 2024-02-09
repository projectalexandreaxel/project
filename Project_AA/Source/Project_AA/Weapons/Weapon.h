// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../CanAttackInterface.h"
#include "Weapon.generated.h"

UCLASS(Abstract, Blueprintable)
class PROJECT_AA_API AWeapon : public AActor, public ICanAttackInterface
{
	GENERATED_BODY()

public:
	virtual void Attack() PURE_VIRTUAL(AWeapon::Attack,);

protected:
	UPROPERTY(EditAnywhere)
	int BaseDamage;

};
