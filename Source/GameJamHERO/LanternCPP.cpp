// Fill out your copyright notice in the Description page of Project Settings.


#include "LanternCPP.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/PostProcessVolume.h"


// Sets default values
ALanternCPP::ALanternCPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	
	Lantern = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lantern"));
	Lantern->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(100.f, 50.f, 30.f));
	BoxCollision->AttachToComponent(Lantern, FAttachmentTransformRules::KeepRelativeTransform);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ALanternCPP::OnOverlapBegin);
}

// Called when something overlaps the BoxCollision
void ALanternCPP::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Overlap Function Called.");
	
	TArray<AActor*> foundVolume;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), foundVolume);
}

// Called when the game starts or when spawned
void ALanternCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALanternCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

