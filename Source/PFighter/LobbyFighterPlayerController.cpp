// Fill out your copyright notice in the Description page of Project Settings.

#include "LobbyFighterPlayerController.h"
#include "FighterPawn.h"
#include "Kismet/KismetMathLibrary.h"

ALobbyFighterPlayerController::ALobbyFighterPlayerController(): Super()
{

}

void ALobbyFighterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &ALobbyFighterPlayerController::MoveForward);
}

void ALobbyFighterPlayerController::MoveRight(float AxisValue)
{
	if (FighterPawn)
	{
		FighterPawn->FighterMoveRight(UKismetMathLibrary::GetRightVector(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)), FMath::Clamp(AxisValue, -1.0f, 1.0f));
	}
}

void ALobbyFighterPlayerController::MoveForward(float AxisValue)
{
	if (FighterPawn)
	{
		FighterPawn->FighterMoveRight(UKismetMathLibrary::GetForwardVector(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)), FMath::Clamp(AxisValue, -1.0f, 1.0f));
	}
}
