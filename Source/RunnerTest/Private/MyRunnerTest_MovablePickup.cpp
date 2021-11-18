// Fill out your copyright notice in the Description page of Project Settings.

#include "MyRunnerTest_MovablePickup.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "RunnerTest_RunnerCharacter.h"

// Sets default values
AMyRunnerTest_MovablePickup::AMyRunnerTest_MovablePickup()
{
	PickupFX = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleFX"));
	PickupFX->SetupAttachment(RootComponent);
	PickupFX->SetAutoActivate(true);

}

// Called when the game starts or when spawned
void AMyRunnerTest_MovablePickup::BeginPlay()
{
	Super::BeginPlay();

	// Bind overlap event
	MeshComp->OnComponentBeginOverlap.AddDynamic(this, &AMyRunnerTest_MovablePickup::HandleOverlap);

}

// Base for pick effect
void AMyRunnerTest_MovablePickup::PlayerEffect_Implementation() 
{
	this->Destroy();
}

// Handle overlap with player
void AMyRunnerTest_MovablePickup::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ARunnerTest_RunnerCharacter* MyCharacter = Cast<ARunnerTest_RunnerCharacter>(OtherActor);
	if (MyCharacter==OtherActor)
	{
		PickupFX->Deactivate();
		PlayerEffect();
	}

}