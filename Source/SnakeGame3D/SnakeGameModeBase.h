// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SnakeGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SNAKEGAME3D_API ASnakeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASnakeGameModeBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	void StartGame();
	void EndGame();

	UPROPERTY(BlueprintReadOnly)
	int PlayerScore;
	void AddScore(int ScoreToAdd);
	
};
