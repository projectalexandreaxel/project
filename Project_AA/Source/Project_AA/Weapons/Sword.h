// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MeleeWeapon.h"
#include "Sword.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_AA_API ASword : public AMeleeWeapon
{
	GENERATED_BODY()

	ASword();

	UPROPERTY(EditAnywhere)
	class UBoxComponent* BoxComponent;

	virtual void Attack() override;
};
