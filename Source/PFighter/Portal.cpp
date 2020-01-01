// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
APortal::APortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetReplicates(false);
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent->Mobility = EComponentMobility::Static;

	PortalRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("PortalRootComponent"));
	PortalRootComponent->SetupAttachment(RootComponent);
	PortalRootComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	PortalRootComponent->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	PortalRootComponent->Mobility = EComponentMobility::Movable;

	PortalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PortalMeshComponent"));
	PortalMesh->SetupAttachment(PortalRootComponent);

	SceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCaptureComponent"));
	SceneCapture->SetupAttachment(RootComponent);
	SceneCapture->bEnableClipPlane = true;
}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	Super::BeginPlay();
	RenderTarget = UKismetRenderingLibrary::CreateRenderTarget2D(GetWorld(), 1980, 1080);
	SceneCapture->TextureTarget = RenderTarget;
	CreateMaterial();
}

// Called every frame
void APortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateSceneCapture();
}

void APortal::UpdateSceneCapture()
{
	if (Target)
	{
		SceneCapture->ClipPlaneBase = Target->GetActorLocation();
		SceneCapture->ClipPlaneNormal = Target->GetActorForwardVector();
		SceneCapture->SetWorldLocationAndRotation(PortalConvertLocation(this, Target, GetCameraLocation()), PortalConvertRotation(this, Target, GetCameraRotation()));
	}
}

FVector APortal::PortalConvertDirection(APortal * CurrentPortal, APortal * TargetPortal, FVector PreviousDirection)
{
	return TargetPortal->GetTransform().TransformVector(CurrentPortal->GetTransform().InverseTransformVector(PreviousDirection).MirrorByVector(FVector(1.0f, 0.0f, 0.0f)).MirrorByVector(FVector(0.0f, 1.0f, 0.0f)));
}

FVector APortal::PortalConvertLocation(APortal * CurrentPortal, APortal * TargetPortal, FVector PreviousLocation)
{
	FTransform CurrentMirroredTransform = FTransform(CurrentPortal->GetActorRotation(), CurrentPortal->GetActorLocation(), FVector(CurrentPortal->GetActorScale3D().X * -1.0f, CurrentPortal->GetActorScale3D().Y * -1.0f, CurrentPortal->GetActorScale3D().Z));
	return TargetPortal->GetTransform().TransformPosition(CurrentMirroredTransform.InverseTransformPosition(PreviousLocation));
}

FRotator APortal::PortalConvertRotation(APortal * CurrentPortal, APortal * TargetPortal, FRotator PreviousRotation)
{
	FVector X, Y, Z;
	UKismetMathLibrary::BreakRotIntoAxes(PreviousRotation, X, Y, Z);
	return UKismetMathLibrary::MakeRotFromXY(PortalConvertDirection(CurrentPortal, TargetPortal, X), PortalConvertDirection(CurrentPortal, TargetPortal, Y));
}

FVector APortal::GetCameraLocation_Implementation()
{
	return FVector();
}

FRotator APortal::GetCameraRotation_Implementation()
{
	return FRotator();
}

