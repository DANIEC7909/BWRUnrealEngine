


#include "MainCameraPlayer.h"
#include <Kismet/GameplayStatics.h>
#include "NuclearForgeGameMode.h"
AMainCameraPlayer::AMainCameraPlayer()
{

	PrimaryActorTick.bCanEverTick = true;
	
}
float cachedSpeed;
AActor* Ghost;
UStaticMeshComponent* GhostMesh;
APlayerController* PlayerController;
ANuclearForgeGameMode* GameMode;
void AMainCameraPlayer::BeginPlay()
{
	Super::BeginPlay();
	cachedSpeed = Speed;
	ChagneGhost(ActorToSpawn);
GameMode =CastChecked<ANuclearForgeGameMode>( UGameplayStatics::GetGameMode(GetWorld()));
GameMode->Player = this;
	 PlayerController = GetWorld()->GetFirstPlayerController();
}
void AMainCameraPlayer::ChagneGhost(UClass* ghost) {
	if (Ghost != nullptr) 
	{
		Ghost->Destroy();
	}

	if (ghost != nullptr) {
		Ghost = GetWorld()->SpawnActor<AActor>(ghost, FVector::Zero(), FRotator::ZeroRotator);
		GhostMesh = Ghost->GetComponentByClass<UStaticMeshComponent>();	
		GhostMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void AMainCameraPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
#pragma region CursorPositionSelection
		double ViewportSizeX, ViewportSizeY;
		PlayerController->GetMousePosition(ViewportSizeX, ViewportSizeY);
		auto ScreenLocation = FVector2D(ViewportSizeX, ViewportSizeY);

		FVector WorldLocation;
		FVector WorldDirection;
	if (PlayerController->DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection))
	{

	
		FCollisionQueryParams CollisionParams;

	

		if (GetWorld()->LineTraceSingleByChannel(HitResult, WorldLocation, WorldLocation + (WorldDirection * 1000000), ECC_Visibility, CollisionParams))
		{
			SurfacePoint = HitResult.ImpactPoint;

			if (Ghost != nullptr)
			{
				
				Ghost->SetActorLocation(FVector(FMath::FloorToInt(SurfacePoint.X), FMath::FloorToInt(SurfacePoint.Y), FMath::FloorToInt(SurfacePoint.Z)));
				if (!HitResult.GetActor()->ActorHasTag("TestCube"))
				{
					GhostMesh->SetMaterial(0, CanBeBuiltMaterial);
				}
				else
				{
					GhostMesh->SetMaterial(0, CannotBeBuiltMaterial);
				}
			}
		}
	}
#pragma endregion

	//in future i have to rewirte this to be more performant.
#pragma region SampleAllSnapPoints
	for (USnapPoint* snapP : GameMode->SnapPoints) {
		GEngine->AddOnScreenDebugMessage(GameMode->SnapPoints.Find(snapP), 5, FColor::Cyan, FString::SanitizeFloat(FVector::Distance(snapP->GetComponentLocation(), Ghost->GetActorLocation())));
		if (FVector::Distance(snapP->GetComponentLocation(), Ghost->GetActorLocation())<DistanceToSnap)
		{

			break;
		}
	}
#pragma endregion
}
#pragma region Movement
void AMainCameraPlayer::MovementForward(float AxisValue)
{
	SetActorLocation(FVector(AxisValue * Speed + GetActorLocation().X,GetActorLocation().Y, GetActorLocation().Z));
}
void AMainCameraPlayer::MovementSide(float AxisValue)
{
	SetActorLocation(FVector(GetActorLocation().X, AxisValue*Speed+ GetActorLocation().Y, GetActorLocation().Z));
}

void AMainCameraPlayer::IncreseSpeed(float value)
{
	AMainCameraPlayer::Speed = value==1? cachedSpeed *2.5f:cachedSpeed;
}
void AMainCameraPlayer::MoveUpDown(float value)
{
SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z+(value*AMainCameraPlayer::UpDownSpeed)));
}
#pragma endregion
void AMainCameraPlayer::PlaceObject()
{
	if (!HitResult.GetActor()->ActorHasTag("TestCube")&& Ghost!=nullptr)
	{
		GetWorld()->SpawnActor<AActor>(ActorToSpawn,Ghost->GetActorLocation(), FRotator::ZeroRotator);
	}
}

void AMainCameraPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCameraPlayer::MovementForward);
	PlayerInputComponent->BindAxis("MoveSide", this, &AMainCameraPlayer::MovementSide);
	PlayerInputComponent->BindAxis("IncreseSpeed",this, &AMainCameraPlayer::IncreseSpeed);
	PlayerInputComponent->BindAxis("MoveUpDown",this, &AMainCameraPlayer::MoveUpDown);

	//Actions
	PlayerInputComponent->BindAction("PlaceObject",IE_Pressed,this, &AMainCameraPlayer::PlaceObject);


}
