// Fill out your copyright notice in the Description page of Project Settings.

#include "DefaultHUD.h"
#include "HUDWidget.h"

void ADefaultHUD::BeginPlay() {
    Super::BeginPlay();

    TSharedPtr<SHUDWidget> HUDWidget = SNew(SHUDWidget);

    UGameViewportClient* ViewportClient = GetWorld()->GetGameViewport();

    ViewportClient->AddViewportWidgetContent(HUDWidget.ToSharedRef());
}

