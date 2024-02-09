// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "MeleeWeapon.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class PROJECT_AA_API AMeleeWeapon : public AWeapon
{
	GENERATED_BODY()

public:
	virtual void Attack() PURE_VIRTUAL(AMeleeWeapon::Attack,);

protected:
	UPROPERTY(EditAnywhere)
	float Range;
};
