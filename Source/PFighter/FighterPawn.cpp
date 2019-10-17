// Fill out your copyright notice in the Description page of Project Settings.

#include "FighterPawn.h"

// Sets default values
AFighterPawn::AFighterPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, CurrentVelocity(FVector::ZeroVector)
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

	if (!CurrentVelocity.IsZero())
	{
		SetActorLocation(GetActorLocation() + CurrentVelocity * DeltaTime);
	}
}

void AFighterPawn::FighterMoveRight_Implementation(float AxisValue)
{
	CurrentVelocity = GetActorRightVector() * AxisValue * FighterMoveSpeed;
}


