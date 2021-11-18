// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RunnerTest_GameModeBase.h"
#include "Components/ArrowComponent.h"
#include "RunnerTest_MovableActor.generated.h"

UCLASS()
class RUNNERTEST_API ARunnerTest_MovableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARunnerTest_MovableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// New root
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* SceneComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* ArrowComp;

	// Attach to root
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComp;

	// Game mode ref
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Game")
	ARunnerTest_GameModeBase* GameMode;
};
