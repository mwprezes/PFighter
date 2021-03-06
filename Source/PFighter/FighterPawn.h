// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FighterPawn.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EActualInput : uint8
{
	None,
	Punch,
	Kick,
	Special,
	Ultimate
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

	// Replicated inputs

	//Movement
	void FighterMoveRight(float AxisValue);
	UFUNCTION(Reliable, Server)
	void ServerFighterMoveRight(float AxisValue);
	UFUNCTION(Reliable, NetMulticast)
	void MulticastFighterMoveRight(float AxisValue);

	//Jump
	void FighterJump();
	UFUNCTION(Reliable, Server)
	void ServerFighterJump();
	UFUNCTION(Reliable, NetMulticast)
	void MulticastFighterJump();

	//CrouchPressed
	void FighterCrouchPressed();
	UFUNCTION(Reliable, Server)
	void ServerFighterCrouchPressed();
	UFUNCTION(Reliable, NetMulticast)
	void MulticastFighterCrouchPressed();

	//CrouchReleased
	void FighterCrouchReleased();
	UFUNCTION(Reliable, Server)
	void ServerFighterCrouchReleased();
	UFUNCTION(Reliable, NetMulticast)
	void MulticastFighterCrouchReleased();

	//Punch
	void FighterPunch();
	UFUNCTION(Reliable, Server)
	void ServerFighterPunch();
	UFUNCTION(Reliable, NetMulticast)
	void MulticastFighterPunch();

	//Kick
	void FighterKick();
	UFUNCTION(Reliable, Server)
	void ServerFighterKick();
	UFUNCTION(Reliable, NetMulticast)
	void MulticastFighterKick();

	//BlockPressed
	void FighterBlockPressed();
	UFUNCTION(Reliable, Server)
	void ServerFighterBlockPressed();
	UFUNCTION(Reliable, NetMulticast)
	void MulticastFighterBlockPressed();

	//BlockReleased
	void FighterBlockReleased();
	UFUNCTION(Reliable, Server)
	void ServerFighterBlockReleased();
	UFUNCTION(Reliable, NetMulticast)
	void MulticastFighterBlockReleased();

	//Special
	void FighterSpecial();
	UFUNCTION(Reliable, Server)
	void ServerFighterSpecial();
	UFUNCTION(Reliable, NetMulticast)
	void MulticastFighterSpecial();

	//Ultimate
	void FighterUltimate();
	UFUNCTION(Reliable, Server)
	void ServerFighterUltimate();
	UFUNCTION(Reliable, NetMulticast)
	void MulticastFighterUltimate();

	//ConsumeInput
	UFUNCTION(BlueprintCallable)
	void FighterConsumeInput();
	UFUNCTION(Reliable, Server)
	void ServerFighterConsumeInput();
	UFUNCTION(Reliable, NetMulticast)
	void MulticastFighterConsumeInput();

	//End of replicated inputs

	//Here implement mechanics of starting blocking
	UFUNCTION(BlueprintImplementableEvent)
	void Block();

	//Here implement mechanics of ending blocking
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UnBlock();

protected:

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanMoveInAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsBlocking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FighterMoveSpeed;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
	EActualInput ActualInput;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};
