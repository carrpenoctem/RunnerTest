// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RunnerTest_GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class RUNNERTEST_API ARunnerTest_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	// base game speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	float GameSpeed = 1;
	
};

