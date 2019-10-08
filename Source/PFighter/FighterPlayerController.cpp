// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterPlayerController.h"

AFighterPlayerController::AFighterPlayerController()
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

void AFighterPlayerController::MoveRight(float AxisValue)
{
	if (AxisValue != 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Move axis value %f"), AxisValue);
	}
}

void AFighterPlayerController::Jump()
{
	UE_LOG(LogTemp, Warning, TEXT("Jump"));
}

void AFighterPlayerController::Crouch()
{
	UE_LOG(LogTemp, Warning, TEXT("Crouch"));
}

void AFighterPlayerController::Punch()
{
	UE_LOG(LogTemp, Warning, TEXT("Punch"));
}

void AFighterPlayerController::Kick()
{
	UE_LOG(LogTemp, Warning, TEXT("Kick"));
}

void AFighterPlayerController::Block()
{
	UE_LOG(LogTemp, Warning, TEXT("Block"));
}

void AFighterPlayerController::Special()
{
	UE_LOG(LogTemp, Warning, TEXT("Special"));
}

void AFighterPlayerController::Ultimate()
{
	UE_LOG(LogTemp, Warning, TEXT("Ultimate"));
}
