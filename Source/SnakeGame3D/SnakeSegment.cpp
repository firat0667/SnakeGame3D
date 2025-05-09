// Fill out your copyright notice in the Description page of Project Settings.
#include "SnakeSegment.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASnakeSegment::ASnakeSegment()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SegmentMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SegmentMesh"));
	RootComponent = SegmentMesh;

}

// Called when the game starts or when spawned
void ASnakeSegment::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASnakeSegment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, FollowSpeed);
	SetActorLocation(NewLocation);
}
void ASnakeSegment::SetTargetLocation(FVector NewTarget)
{
	TargetLocation = NewTarget;
}
