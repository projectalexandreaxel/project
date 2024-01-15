// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "DefaultHUD.generated.h"

/**
 * 
 */
UCLASS()
class ADefaultHUD : public AHUD
{
	GENERATED_BODY()

public:
    ADefaultHUD();

protected:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UUserWidget> HUDWidgetClass;

protected:
	virtual void BeginPlay() override;
};
