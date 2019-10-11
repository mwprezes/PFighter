// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterPlayerController.h"
#include "FighterPawn.h"

AFighterPlayerController::AFighterPlayerController() 
	: FighterPawn(nullptr)
{

}

void AFighterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveRight", this, &AFighterPlayerController::MoveRight);

	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AFighterPlayerController::Jump);
	InputComponent->BindAction("Crouch", EInputEvent::IE_Pressed, this, &AFighterPlayerController::Crouch);
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

void AFighterPlayerController::MoveRight(float AxisValue)
{
	if (FighterPawn && AxisValue != 0.0f)
	{
		FighterPawn->MoveRight(FMath::Clamp(AxisValue, -1.0f, 1.0f));
	}
}

void AFighterPlayerController::Jump()
{
	if (FighterPawn)
	{
		FighterPawn->Jump();
	}
}

void AFighterPlayerController::Crouch()
{
	if (FighterPawn)
	{
		FighterPawn->Crouch();
	}
}

void AFighterPlayerController::Punch()
{
	if (FighterPawn)
	{
		FighterPawn->Punch();
	}
}

void AFighterPlayerController::Kick()
{
	if (FighterPawn)
	{
		FighterPawn->Kick();
	}
}

void AFighterPlayerController::Block()
{
	if (FighterPawn)
	{
		FighterPawn->Block();
	}
}

void AFighterPlayerController::Special()
{
	if (FighterPawn)
	{
		FighterPawn->Special();
	}
}

void AFighterPlayerController::Ultimate()
{
	if (FighterPawn)
	{
		FighterPawn->Ultimate();
	}
}
