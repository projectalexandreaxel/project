// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableInterface.h"
#include "Chest.generated.h"

UCLASS()
class PROJECT_AA_API AChest : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere)
	FVector ChestDimensions = FVector(50.f, 50.f, 25.f);

public:	
	// Sets default values for this actor's properties
	AChest();

public:
	virtual void Interact() override;
};
