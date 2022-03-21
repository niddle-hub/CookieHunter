#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CookieHunterMovementComponent.generated.h"

UCLASS()
class COOKIEHUNTER_API UCookieHunterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	virtual float GetMaxSpeed() const override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character|Movement|Sprint", meta = (ClampMin = 0.f, UIMin = 0.f))
	float SprintSpeed = 500.f;
	
private:
	bool IsAffectedBySpeedAbility = false;
	
};
