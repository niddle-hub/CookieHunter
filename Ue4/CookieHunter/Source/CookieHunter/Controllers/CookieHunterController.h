#pragma once

#include "CoreMinimal.h"
#include "CookieHunter/CookieHunterCharacter.h"
#include "GameFramework/PlayerController.h"
#include "CookieHunterController.generated.h"

UCLASS()
class COOKIEHUNTER_API ACookieHunterController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetPawn(APawn* InPawn) override;
	
protected:
	virtual void SetupInputComponent() override;

private:
	TSoftObjectPtr<ACookieHunterCharacter> CachedCharacter;
	
	void MoveForward(float Value);
	void MoveRight(float Value);
	
};
