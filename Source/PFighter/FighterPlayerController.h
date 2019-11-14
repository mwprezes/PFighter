// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FighterPlayerController.generated.h"

class AFighterPawn;

UENUM(BlueprintType)
enum class EControllerStateEnum : uint8
{
	Lobby,
	Game
};

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
	virtual void MoveRight(float AxisValue);

	//Functions binded to input actions
	void Jump();
	void CrouchPressed();
	void CrouchReleased();

	void Punch();
	void Kick();
	void Block();

	void Special();
	void Ultimate();
};
