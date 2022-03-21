#include "CookieHunterCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CookieHunterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

ACookieHunterCharacter::ACookieHunterCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCookieHunterMovementComponent>(CharacterMovementComponentName))
{
	CookieHunterMovementComponent = StaticCast<UCookieHunterMovementComponent*>(GetCharacterMovement());
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring arm"));
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->bInheritPitch = false;
	SpringArmComponent->bInheritYaw = false;
	SpringArmComponent->SetupAttachment(RootComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->bUsePawnControlRotation = false;
	CameraComponent->SetupAttachment(SpringArmComponent);

	GetCharacterMovement()->bOrientRotationToMovement = 1;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
}

void ACookieHunterCharacter::BeginPlay()
{
	Super::BeginPlay();
}


void ACookieHunterCharacter::MoveForward(float Value)
{
	if ((GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling()) && !FMath::IsNearlyZero(Value, 1e-6f))
	{
		const FRotator YawRotator(0.f, GetControlRotation().Yaw, 0.f);
		const FVector ForwardVector = YawRotator.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardVector, Value);
	}
}

void ACookieHunterCharacter::MoveRight(float Value)
{
	if ((GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling()) && !FMath::IsNearlyZero(Value, 1e-6f))
	{
		const FRotator YawRotator(0.f, GetControlRotation().Yaw, 0.f);
		const FVector RightVector = YawRotator.RotateVector(FVector::RightVector);
		AddMovementInput(RightVector, Value);
	}
}
