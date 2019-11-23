// Fill out your copyright notice in the Description page of Project Settings.

#include "FighterPawn.h"

// Sets default values
AFighterPawn::AFighterPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, FighterMoveSpeed(100.0f)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	NetUpdateFrequency = 60.0f;
}

void AFighterPawn::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveRight", this, &AFighterPawn::FighterMoveRight);
	InputComponent->BindAxis("MoveForward", this, &AFighterPawn::FighterMoveForward);

	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AFighterPawn::FighterJump);
	InputComponent->BindAction("Crouch", EInputEvent::IE_Pressed, this, &AFighterPawn::FighterCrouchPressed);
	InputComponent->BindAction("Crouch", EInputEvent::IE_Released, this, &AFighterPawn::FighterCrouchReleased);
	InputComponent->BindAction("Punch", EInputEvent::IE_Pressed, this, &AFighterPawn::FighterPunch);
	InputComponent->BindAction("Kick", EInputEvent::IE_Pressed, this, &AFighterPawn::FighterKick);
	InputComponent->BindAction("Block", EInputEvent::IE_Pressed, this, &AFighterPawn::FighterBlock);
	InputComponent->BindAction("Special", EInputEvent::IE_Pressed, this, &AFighterPawn::FighterSpecial);
	InputComponent->BindAction("Ultimate", EInputEvent::IE_Pressed, this, &AFighterPawn::FighterUltimate);
}

// Called when the game starts or when spawned
void AFighterPawn::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AFighterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFighterPawn::FighterMoveRight_Implementation(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), AxisValue * FighterMoveSpeed);
}

void AFighterPawn::FighterMoveForward_Implementation(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), AxisValue * FighterMoveSpeed);
}

void AFighterPawn::FighterJump_Implementation()
{
	//Jump();
}

void AFighterPawn::FighterCrouchPressed_Implementation()
{
	
}

void AFighterPawn::FighterCrouchReleased_Implementation()
{

}


