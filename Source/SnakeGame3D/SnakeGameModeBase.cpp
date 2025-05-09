// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

ASnakeGameModeBase::ASnakeGameModeBase()
{
	// Set this game mode to call Tick() every frame.
	// PrimaryActorTick.bCanEverTick = true;
}

void ASnakeGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// Initialize PlayerScore to 0
	StartGame();
}
void ASnakeGameModeBase::StartGame()
{
	// Logic to start the game
	UE_LOG(LogTemp, Warning, TEXT("Game Started"));
	PlayerScore = 0;
}
void ASnakeGameModeBase::EndGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Game Ended! Final Score: %d"), PlayerScore);
	// Gelecekte Outro ekranýna geçiþ vs. burada olacak
}
void ASnakeGameModeBase::AddScore(int32 Amount)
{
	PlayerScore += Amount;
	UE_LOG(LogTemp, Log, TEXT("Score Updated: %d"), PlayerScore);
}

