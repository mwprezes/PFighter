// Fill out your copyright notice in the Description page of Project Settings.

#include "FighterPawn.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AFighterPawn::AFighterPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root"));

	Mesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("FighterBodyMesh"));
	Mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
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


