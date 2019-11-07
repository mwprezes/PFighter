// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterPlayerController.h"
#include "FighterPawn.h"
#include "Kismet/KismetMathLibrary.h"

AFighterPlayerController::AFighterPlayerController() 
	: FighterPawn(nullptr)
	, ActualState(EControllerStateEnum::Game)
{

}

void AFighterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveRight", this, &AFighterPlayerController::MoveRight);
	InputComponent->BindAxis("MoveForward", this, &AFighterPlayerController::MoveForward);

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

void AFighterPlayerController::MoveRight(float AxisValue)
{
	if (FighterPawn)
	{
		switch (ActualState)
		{
		case EControllerStateEnum::Game:
			FighterPawn->FighterMoveRight(FighterPawn->GetActorRightVector(), FMath::Clamp(AxisValue, -1.0f, 1.0f));
			break;
		case EControllerStateEnum::Lobby:
			FighterPawn->FighterMoveRight(UKismetMathLibrary::GetRightVector(FRotator(0.0f, GetControlRotation().Yaw, 0.0f))
				, FMath::Clamp(AxisValue, -1.0f, 1.0f));
			break;
		default:
			break;
		}
	}
}

void AFighterPlayerController::MoveForward(float AxisValue)
{
	if (FighterPawn)
	{
		switch (ActualState)
		{
		case EControllerStateEnum::Game:
			break;
		case EControllerStateEnum::Lobby:
			FighterPawn->FighterMoveRight(UKismetMathLibrary::GetForwardVector(FRotator(0.0f, GetControlRotation().Yaw, 0.0f))
				, FMath::Clamp(AxisValue, -1.0f, 1.0f));
			break;
		default:
			break;
		}
	}
}

void AFighterPlayerController::Jump()
{
	if (FighterPawn)
	{
		FighterPawn->FighterJump();
	}
}

void AFighterPlayerController::CrouchPressed()
{
	if (FighterPawn)
	{
		FighterPawn->FighterCrouchPressed();
	}
}

void AFighterPlayerController::CrouchReleased()
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
