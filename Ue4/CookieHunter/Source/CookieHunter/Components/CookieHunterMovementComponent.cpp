#include "CookieHunterMovementComponent.h"

float UCookieHunterMovementComponent::GetMaxSpeed() const
{
	float Result = Super::GetMaxSpeed();
	
	if (IsAffectedBySpeedAbility)
	{
		Result = SprintSpeed;
	}

	return Result;
}
