// Copyright Epic Games, Inc. All Rights Reserved.

#include "DefaultGameMode.h"
#include "DefaultCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "DefaultPlayerController.h"

ADefaultGameMode::ADefaultGameMode()
{
	DefaultPawnClass = ADefaultCharacter::StaticClass();
	PlayerControllerClass = ADefaultPlayerController::StaticClass();
}