#include "SnakeCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "SnakeSegment.h"

ASnakeCharacter::ASnakeCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	HeadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeadMesh"));
	RootComponent = HeadMesh;

	// Baþlangýç yönü ileri (X ekseni)
	CurrentDirection = FVector::ForwardVector;
	NextDirection = FVector::ForwardVector;
}

void ASnakeCharacter::BeginPlay()
{
	Super::BeginPlay();

	SpawnInitialSegments(); 
}


void ASnakeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Ters yöne dönüþü engelle
	if (!NextDirection.Equals(-CurrentDirection))
	{
		CurrentDirection = NextDirection;
	}

	FVector NewLocation = GetActorLocation() + (CurrentDirection * MoveSpeed * DeltaTime);
	SetActorLocation(NewLocation);
}

void ASnakeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveUp", IE_Pressed, this, &ASnakeCharacter::MoveUp);
	PlayerInputComponent->BindAction("MoveDown", IE_Pressed, this, &ASnakeCharacter::MoveDown);
	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &ASnakeCharacter::MoveLeft);
	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &ASnakeCharacter::MoveRight);
}

void ASnakeCharacter::MoveUp()
{
	NextDirection = FVector::ForwardVector;
}

void ASnakeCharacter::MoveDown()
{
	NextDirection = -FVector::ForwardVector;
}

void ASnakeCharacter::MoveRight()
{
	NextDirection = FVector::RightVector;
}

void ASnakeCharacter::MoveLeft()
{
	NextDirection = -FVector::RightVector;
}
void ASnakeCharacter::SpawnInitialSegments()
{
	FVector SpawnLocation = GetActorLocation();

	for (int32 i = 0; i < InitialSegmentCount; ++i)
	{
		FVector Offset = -CurrentDirection * i * 100.0f;
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;

		ASnakeSegment* NewSegment = GetWorld()->SpawnActor<ASnakeSegment>(
			SegmentClass,
			SpawnLocation + Offset,
			FRotator::ZeroRotator,
			SpawnParams
		);

		if (NewSegment)
		{
			NewSegment->SetTargetLocation(SpawnLocation + Offset); 
			SnakeSegments.Add(NewSegment);
		}
	}
}


