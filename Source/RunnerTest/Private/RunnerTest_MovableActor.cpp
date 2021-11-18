// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerTest_MovableActor.h"

// Sets default values
ARunnerTest_MovableActor::ARunnerTest_MovableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set up root
	SceneComp = CreateDefaultSubobject <USceneComponent>(TEXT("SceneComp"));
	RootComponent = SceneComp;

	// Direction arrow for debugging
	ArrowComp = CreateDefaultSubobject <UArrowComponent>(TEXT("ArrowComp"));
	ArrowComp->SetupAttachment(RootComponent);

	// Creating tatic mesh 
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	MeshComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ARunnerTest_MovableActor::BeginPlay()
{
	Super::BeginPlay();

	// Get game mode
	GameMode = (ARunnerTest_GameModeBase*)GetWorld()->GetAuthGameMode();
	
}

// Called every frame
void ARunnerTest_MovableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move object down the lane
	FVector Location = GetActorLocation();
	Location += GetActorForwardVector() * 300 * GameMode->GameSpeed * DeltaTime;
	SetActorLocation(Location);
}

