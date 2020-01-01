// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Portal.generated.h"

UCLASS()
class PFIGHTER_API APortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(BlueprintReadOnly)
	USceneComponent* PortalRootComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* PortalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstanceDynamic* MaterialInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextureRenderTarget2D* RenderTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneCaptureComponent2D* SceneCapture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APortal* Target;

	void UpdateSceneCapture();

	FVector PortalConvertDirection(APortal* CurrentPortal, APortal* TargetPortal, FVector PreviousDirection);

	FVector PortalConvertLocation(APortal* CurrentPortal, APortal* TargetPortal, FVector PreviousLocation);

	FRotator PortalConvertRotation(APortal* CurrentPortal, APortal* TargetPortal, FRotator PreviousRotation);

public:
	UFUNCTION(BlueprintImplementableEvent)
	void CreateMaterial();

	UFUNCTION(BlueprintNativeEvent)
	FVector GetCameraLocation();

	UFUNCTION(BlueprintNativeEvent)
	FRotator GetCameraRotation();

};
