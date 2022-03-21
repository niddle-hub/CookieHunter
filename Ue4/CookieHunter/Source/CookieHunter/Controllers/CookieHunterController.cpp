// ReSharper disable CppMemberFunctionMayBeConst
#include "CookieHunterController.h"

void ACookieHunterController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CachedCharacter = Cast<ACookieHunterCharacter>(InPawn);
}

void ACookieHunterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &ACookieHunterController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACookieHunterController::MoveRight);
}

void ACookieHunterController::MoveForward(float Value)
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->MoveForward(Value);
	}
}

void ACookieHunterController::MoveRight(float Value)
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->MoveRight(Value);
	}
}
