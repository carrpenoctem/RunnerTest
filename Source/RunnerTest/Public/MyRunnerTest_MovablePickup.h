// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RunnerTest_MovableActor.h"
#include "MyRunnerTest_MovablePickup.generated.h"


UCLASS()
class RUNNERTEST_API AMyRunnerTest_MovablePickup : public ARunnerTest_MovableActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyRunnerTest_MovablePickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// constant particle effect
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UParticleSystemComponent* PickupFX;

	// effect on player overlap
	UFUNCTION(BlueprintNativeEvent, Category = "Effect")
	void PlayerEffect();

	// launch effect on overlap
	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
	
