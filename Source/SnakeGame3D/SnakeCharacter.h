#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SnakeCharacter.generated.h"

class ASnakeSegment; // ⛔ Bunu yukarıda forward declare et, include gerekmez
UCLASS()
class SNAKEGAME3D_API ASnakeCharacter : public APawn
{
	GENERATED_BODY()

public:
	ASnakeCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* HeadMesh;

	UPROPERTY(EditAnywhere, Category = "Snake")
	TSubclassOf<ASnakeSegment> SegmentClass; 

	UPROPERTY(EditAnywhere, Category = "Snake")
	int32 InitialSegmentCount = 3; 

	UPROPERTY()
	TArray<ASnakeSegment*> SnakeSegments;

	UPROPERTY(EditAnywhere)
	float MoveSpeed = 300.0f;

	FVector CurrentDirection;
	FVector NextDirection;

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	void SpawnInitialSegments(); 
};
