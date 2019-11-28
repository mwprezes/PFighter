// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FighterPawn.generated.h"

UENUM(BlueprintType)
enum class EInputModeEnum : uint8
{
	Lobby,
	Game
};

UCLASS()
class PFIGHTER_API AFighterPawn : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFighterPawn(const FObjectInitializer& ObjectInitializer);

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Reliable, NetMulticast)
	void FighterMoveRight(float AxisValue);
	UFUNCTION(Reliable, NetMulticast)
	void FighterMoveForward(float AxisValue);

	UFUNCTION(Reliable, NetMulticast)
	void FighterJump();
	UFUNCTION(Reliable, NetMulticast)
	void FighterCrouchPressed();
	UFUNCTION(Reliable, NetMulticast)
	void FighterCrouchReleased();

	UFUNCTION(Reliable, NetMulticast)
	void FighterPunch();
	UFUNCTION(Reliable, NetMulticast)
	void FighterKick();
	UFUNCTION(Reliable, NetMulticast)
	void FighterBlock();

	UFUNCTION(Reliable, NetMulticast)
	void FighterSpecial();
	UFUNCTION(Reliable, NetMulticast)
	void FighterUltimate();

protected:

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FighterMoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EInputModeEnum ActualInputMode;
};
