// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterPlayerController.h"
#include "FighterPawn.h"

AFighterPlayerController::AFighterPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, FighterPawn(nullptr)
{

}

void AFighterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveRight", this, &AFighterPlayerController::MoveRight);

	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AFighterPlayerController::Jump);
	InputComponent->BindAction("Crouch", EInputEvent::IE_Pressed, this, &AFighterPlayerController::CrouchPressed);
	InputComponent->BindAction("Crouch", EInputEvent::IE_Released, this, &AFighterPlayerController::CrouchReleased);
	InputComponent->BindAction("Punch", EInputEvent::IE_Pressed, this, &AFighterPlayerController::Punch);
	InputComponent->BindAction("Kick", EInputEvent::IE_Pressed, this, &AFighterPlayerController::Kick);
	InputComponent->BindAction("Block", EInputEvent::IE_Pressed, this, &AFighterPlayerController::Block);
	InputComponent->BindAction("Special", EInputEvent::IE_Pressed, this, &AFighterPlayerController::Special);
	InputComponent->BindAction("Ultimate", EInputEvent::IE_Pressed, this, &AFighterPlayerController::Ultimate);
}

void AFighterPlayerController::OnPossess(APawn * InPawn)
{
	Super::OnPossess(InPawn);
	if (AFighterPawn* NewPawn = Cast<AFighterPawn>(InPawn))
	{
		FighterPawn = NewPawn;
	}
}

void AFighterPlayerController::MoveRight_Implementation(float AxisValue)
{
	if (FighterPawn && AxisValue != 0.0f)
	{
		FighterPawn->FighterMoveRight(FighterPawn->GetActorRightVector(), FMath::Clamp(AxisValue, -1.0f, 1.0f));
	}
}

void AFighterPlayerController::Jump_Implementation()
{
	if (FighterPawn)
	{
		FighterPawn->FighterJump();
	}
}

void AFighterPlayerController::CrouchPressed_Implementation()
{
	if (FighterPawn)
	{
		FighterPawn->FighterCrouchPressed();
	}
}

void AFighterPlayerController::CrouchReleased_Implementation()
{
	if (FighterPawn)
	{
		FighterPawn->FighterCrouchReleased();
	}
}

void AFighterPlayerController::Punch()
{
	if (FighterPawn)
	{
		FighterPawn->FighterPunch();
	}
}

void AFighterPlayerController::Kick()
{
	if (FighterPawn)
	{
		FighterPawn->FighterKick();
	}
}

void AFighterPlayerController::Block()
{
	if (FighterPawn)
	{
		FighterPawn->FighterBlock();
	}
}

void AFighterPlayerController::Special()
{
	if (FighterPawn)
	{
		FighterPawn->FighterSpecial();
	}
}

void AFighterPlayerController::Ultimate()
{
	if (FighterPawn)
	{
		FighterPawn->FighterUltimate();
	}
}
