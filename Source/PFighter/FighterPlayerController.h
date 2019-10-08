// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FighterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PFIGHTER_API AFighterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AFighterPlayerController();

	virtual void SetupInputComponent();

protected:
	//Function binded to input axis
	void MoveRight(float AxisValue);

	void Jump();
	void Crouch();

	void Punch();
	void Kick();
	void Block();

	void Special();
	void Ultimate();

	
};
