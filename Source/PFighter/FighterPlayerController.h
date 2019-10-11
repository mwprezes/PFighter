// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FighterPlayerController.generated.h"

class AFighterPawn;

/**
 * 
 */
UCLASS()
class PFIGHTER_API AFighterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AFighterPlayerController();

	virtual void SetupInputComponent() override;

protected:
	// On posses override
	virtual void OnPossess(APawn * InPawn) override;

	// Our pawn of FighterPawnType
	AFighterPawn* FighterPawn;

	//Function binded to input axis
	void MoveRight(float AxisValue);

	//Functions binded to input actions
	void Jump();
	void Crouch();

	void Punch();
	void Kick();
	void Block();

	void Special();
	void Ultimate();

	
};
