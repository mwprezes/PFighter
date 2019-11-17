// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FighterPlayerController.h"
#include "LobbyFighterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PFIGHTER_API ALobbyFighterPlayerController : public AFighterPlayerController
{
	GENERATED_BODY()
	
public:
	ALobbyFighterPlayerController(const FObjectInitializer& ObjectInitializer);

	virtual void SetupInputComponent() override;

	//Function binded to input axis
protected:
	virtual void MoveRight_Implementation(float AxisValue) override;
	UFUNCTION(Reliable, Server)
	void MoveForward(float AxisValue);
};
