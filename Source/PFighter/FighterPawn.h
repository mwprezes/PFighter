// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FighterPawn.generated.h"

UCLASS()
class PFIGHTER_API AFighterPawn : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFighterPawn(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Reliable, NetMulticast)
	void FighterMoveRight(FVector Direction, float AxisValue);
	UFUNCTION(Reliable, NetMulticast)
	void FighterMoveForward(FVector Direction, float AxisValue);

	UFUNCTION(Reliable, NetMulticast)
	void FighterJump();
	UFUNCTION(Reliable, NetMulticast)
	void FighterCrouchPressed();
	UFUNCTION(Reliable, NetMulticast)
	void FighterCrouchReleased();

	UFUNCTION(BlueprintImplementableEvent)
	void FighterPunch();
	UFUNCTION(BlueprintImplementableEvent)
	void FighterKick();
	UFUNCTION(BlueprintImplementableEvent)
	void FighterBlock();

	UFUNCTION(BlueprintImplementableEvent)
	void FighterSpecial();
	UFUNCTION(BlueprintImplementableEvent)
	void FighterUltimate();

protected:

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FighterMoveSpeed;
};
