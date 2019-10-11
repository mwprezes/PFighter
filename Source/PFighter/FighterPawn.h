// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FighterPawn.generated.h"

UCLASS()
class PFIGHTER_API AFighterPawn : public APawn
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

	UFUNCTION(BlueprintImplementableEvent)
	void MoveRight(float AxisValue);

	UFUNCTION(BlueprintImplementableEvent)
	void Jump();
	UFUNCTION(BlueprintImplementableEvent)
	void Crouch();

	UFUNCTION(BlueprintImplementableEvent)
	void Punch();
	UFUNCTION(BlueprintImplementableEvent)
	void Kick();
	UFUNCTION(BlueprintImplementableEvent)
	void Block();

	UFUNCTION(BlueprintImplementableEvent)
	void Special();
	UFUNCTION(BlueprintImplementableEvent)
	void Ultimate();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* Mesh;
};
