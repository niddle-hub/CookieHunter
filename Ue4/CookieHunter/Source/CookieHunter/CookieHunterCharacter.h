#pragma once

#include "CoreMinimal.h"
#include "Components/CookieHunterMovementComponent.h"
#include "GameFramework/Character.h"
#include "CookieHunterCharacter.generated.h"


UCLASS(config=Game)
class ACookieHunterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACookieHunterCharacter(const FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;
	
	void MoveForward(float Value);
	void MoveRight(float Value);

	FORCEINLINE UCookieHunterMovementComponent* GetBaseCharacterMovementComponent() const { return CookieHunterMovementComponent; }

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	UPROPERTY()
	UCookieHunterMovementComponent* CookieHunterMovementComponent;

};

