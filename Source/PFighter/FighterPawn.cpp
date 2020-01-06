// Fill out your copyright notice in the Description page of Project Settings.

#include "FighterPawn.h"
#include "GameFramework/PawnMovementComponent.h"

#include "Net/UnrealNetwork.h"

// Sets default values
AFighterPawn::AFighterPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, bCanMoveInAir(false)
	, bIsBlocking(false)
	, FighterMoveSpeed(100.0f)
	, ActualInput(EActualInput::None)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	NetUpdateFrequency = 60.0f;
	GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;
}

void AFighterPawn::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveRight", this, &AFighterPawn::FighterMoveRight);

	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AFighterPawn::FighterJump);
	InputComponent->BindAction("Crouch", EInputEvent::IE_Pressed, this, &AFighterPawn::FighterCrouchPressed);
	InputComponent->BindAction("Crouch", EInputEvent::IE_Released, this, &AFighterPawn::FighterCrouchReleased);
	InputComponent->BindAction("Punch", EInputEvent::IE_Pressed, this, &AFighterPawn::FighterPunch);
	InputComponent->BindAction("Kick", EInputEvent::IE_Pressed, this, &AFighterPawn::FighterKick);
	InputComponent->BindAction("Block", EInputEvent::IE_Pressed, this, &AFighterPawn::FighterBlockPressed);
	InputComponent->BindAction("Block", EInputEvent::IE_Released, this, &AFighterPawn::FighterBlockReleased);
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

void AFighterPawn::FighterMoveRight(float AxisValue)
{
	if (Role == ROLE_Authority)
	{
		MulticastFighterMoveRight(AxisValue);
	}
	else
	{
		if ((bCanMoveInAir || !GetMovementComponent()->IsFalling()) && !bIsBlocking)
		{
			AddMovementInput(FVector(0.0f, 1.0f, 0.0f), AxisValue * FighterMoveSpeed);
			ServerFighterMoveRight(AxisValue);
		}
	}
}

void AFighterPawn::ServerFighterMoveRight_Implementation(float AxisValue)
{
	MulticastFighterMoveRight(AxisValue);
}

void AFighterPawn::MulticastFighterMoveRight_Implementation(float AxisValue)
{
	if ((bCanMoveInAir || !GetMovementComponent()->IsFalling()) && !bIsBlocking)
	{
		AddMovementInput(FVector(0.0f, 1.0f, 0.0f), AxisValue * FighterMoveSpeed);
	}
}

void AFighterPawn::FighterJump()
{
	if (Role == ROLE_Authority)
	{
		MulticastFighterJump();
	}
	else
	{
		if (!GetMovementComponent()->IsFalling() && !bIsBlocking)
		{
			if(!bCanMoveInAir) GetMovementComponent()->StopMovementImmediately();
			Jump();
			ServerFighterJump();
		}
	}
}

void AFighterPawn::ServerFighterJump_Implementation()
{
	MulticastFighterJump();
}

void AFighterPawn::MulticastFighterJump_Implementation()
{
	if (!GetMovementComponent()->IsFalling() && !bIsBlocking)
	{
		if(!bCanMoveInAir) GetMovementComponent()->StopMovementImmediately();
		Jump();
	}
}

void AFighterPawn::FighterCrouchPressed()
{
	if (Role == ROLE_Authority)
	{
		MulticastFighterCrouchPressed();
	}
	else
	{
		if (!GetMovementComponent()->IsFalling())
		{
			Crouch();
			ServerFighterCrouchPressed();
		}
	}
}

void AFighterPawn::ServerFighterCrouchPressed_Implementation()
{
	MulticastFighterCrouchPressed();
}

void AFighterPawn::MulticastFighterCrouchPressed_Implementation()
{
	if (!GetMovementComponent()->IsFalling())
	{
		Crouch();
	}
}

void AFighterPawn::FighterCrouchReleased()
{
	if (Role == ROLE_Authority)
	{
		MulticastFighterCrouchReleased();
	}
	else
	{
		if (!GetMovementComponent()->IsFalling())
		{
			UnCrouch();
			ServerFighterCrouchReleased();
		}
	}
}

void AFighterPawn::ServerFighterCrouchReleased_Implementation()
{
	MulticastFighterCrouchReleased();
}

void AFighterPawn::MulticastFighterCrouchReleased_Implementation()
{
	if (!GetMovementComponent()->IsFalling())
	{
		UnCrouch();
	}
}

void AFighterPawn::FighterPunch()
{
	if(Role == ROLE_Authority)
	{
		MulticastFighterPunch();
	}
	else
	{
		ActualInput = EActualInput::Punch;
		ServerFighterPunch();
	}
}

void AFighterPawn::ServerFighterPunch_Implementation()
{
	MulticastFighterPunch();
}

void AFighterPawn::MulticastFighterPunch_Implementation()
{
	ActualInput = EActualInput::Punch;
}

void AFighterPawn::FighterKick()
{
	if (Role == ROLE_Authority)
	{
		MulticastFighterKick();
	}
	else
	{
		ActualInput = EActualInput::Kick;
		ServerFighterKick();
	}
}

void AFighterPawn::ServerFighterKick_Implementation()
{
	MulticastFighterKick();
}

void AFighterPawn::MulticastFighterKick_Implementation()
{
	ActualInput = EActualInput::Kick;
}

void AFighterPawn::FighterBlockPressed()
{
	if (Role == ROLE_Authority)
	{
		MulticastFighterBlockPressed();
	}
	else
	{
		if (!GetMovementComponent()->IsFalling())
		{
			Block();
			ServerFighterBlockPressed();
		}
	}
}

void AFighterPawn::ServerFighterBlockPressed_Implementation()
{
	MulticastFighterBlockPressed();
}

void AFighterPawn::MulticastFighterBlockPressed_Implementation()
{
	if (!GetMovementComponent()->IsFalling())
	{
		Block();
	}
}

void AFighterPawn::FighterBlockReleased()
{
	if (Role == ROLE_Authority)
	{
		MulticastFighterBlockReleased();
	}
	else
	{
		UnBlock();
		ServerFighterBlockReleased();
	}
}

void AFighterPawn::ServerFighterBlockReleased_Implementation()
{
	MulticastFighterBlockReleased();
}

void AFighterPawn::MulticastFighterBlockReleased_Implementation()
{
	UnBlock();
}

void AFighterPawn::FighterSpecial()
{
	if (Role == ROLE_Authority)
	{
		MulticastFighterSpecial();
	}
	else
	{
		ActualInput = EActualInput::Special;
		ServerFighterSpecial();
	}
}

void AFighterPawn::ServerFighterSpecial_Implementation()
{
	MulticastFighterSpecial();
}

void AFighterPawn::MulticastFighterSpecial_Implementation()
{
	ActualInput = EActualInput::Special;
}

void AFighterPawn::FighterUltimate()
{
	if (Role == ROLE_Authority)
	{
		MulticastFighterUltimate();
	}
	else
	{
		ActualInput = EActualInput::Ultimate;
		ServerFighterUltimate();
	}
}

void AFighterPawn::ServerFighterUltimate_Implementation()
{
	MulticastFighterUltimate();
}

void AFighterPawn::MulticastFighterUltimate_Implementation()
{
	ActualInput = EActualInput::Ultimate;
}

void AFighterPawn::FighterConsumeInput()
{
	if (Role == ROLE_Authority)
	{
		MulticastFighterConsumeInput();
	}
	else
	{
		ActualInput = EActualInput::None;
		ServerFighterConsumeInput();
	}
}

void AFighterPawn::ServerFighterConsumeInput_Implementation()
{
	MulticastFighterConsumeInput();
}

void AFighterPawn::MulticastFighterConsumeInput_Implementation()
{
	ActualInput = EActualInput::None;
}

void AFighterPawn::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFighterPawn, ActualInput);
}
