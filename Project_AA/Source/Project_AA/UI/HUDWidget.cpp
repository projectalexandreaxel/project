// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SHUDWidget::Construct(const FArguments& InArgs) {
	ChildSlot
	[
		SNew(STextBlock)
		.Text(FText::FromString(TEXT("PATATATA")))
	];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION