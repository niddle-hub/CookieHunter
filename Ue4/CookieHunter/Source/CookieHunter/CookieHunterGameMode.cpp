// Copyright Epic Games, Inc. All Rights Reserved.

#include "CookieHunterGameMode.h"
#include "CookieHunterCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACookieHunterGameMode::ACookieHunterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
