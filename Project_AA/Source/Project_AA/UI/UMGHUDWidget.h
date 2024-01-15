// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SlateHUDWidget.h"
#include "UMGHUDWidget.generated.h"

UCLASS()
class UHUDWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void ReleaseSlateResources(bool bReleaseChildren) override;

protected:
    virtual TSharedRef<SWidget> RebuildWidget() override;

    TSharedPtr<SHUDWidget> HUDWidget;
};
