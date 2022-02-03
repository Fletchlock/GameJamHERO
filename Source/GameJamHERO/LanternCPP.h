// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "LanternCPP.generated.h"

UCLASS()
class GAMEJAMHERO_API ALanternCPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALanternCPP();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		USceneComponent* Root;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Lantern;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* BoxCollision;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	
};
