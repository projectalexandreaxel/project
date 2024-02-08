// Fill out your copyright notice in the Description page of Project Settings.

#include "DefaultHUD.h"
#include "UMGHUDWidget.h"
#include "Blueprint/UserWidget.h"

ADefaultHUD::ADefaultHUD() {
    HUDWidgetClass = UHUDWidget::StaticClass();
}

void ADefaultHUD::BeginPlay() {
    Super::BeginPlay();

    UHUDWidget* HUDWidget = CreateWidget<UHUDWidget>(GetWorld(), HUDWidgetClass);

    HUDWidget->AddToViewport();
}

