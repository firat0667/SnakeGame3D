// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeSegment.generated.h"

UCLASS()
class SNAKEGAME3D_API ASnakeSegment : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnakeSegment();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Function to set the segment's mesh we can set the mesh in the editor but we cant set in the blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* SegmentMesh;


	UPROPERTY(EditAnywhere)
	float FollowSpeed = 15.0f;
	void SetTargetLocation(FVector NewTarget);

private:
	FVector TargetLocation;


};
