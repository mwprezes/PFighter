// Fill out your copyright notice in the Description page of Project Settings.

#include "FighterPawn.h"

// Sets default values
AFighterPawn::AFighterPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, FighterMoveSpeed(100.0f)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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

void AFighterPawn::FighterJump_Implementation()
{
	Jump();
}

void AFighterPawn::FighterCrouchPressed_Implementation()
{
	
}

void AFighterPawn::FighterCrouchReleased_Implementation()
{

}


