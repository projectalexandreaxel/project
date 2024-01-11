// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project_AAGameMode.h"
#include "UI/DefaultHUD.h"

AProject_AAGameMode::AProject_AAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	HUDClass = ADefaultHUD::StaticClass();
}
