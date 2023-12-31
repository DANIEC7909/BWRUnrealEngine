// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MainCameraPlayer.generated.h"

UCLASS()
class NUCLEARFORGE_API AMainCameraPlayer : public APawn
{
	GENERATED_BODY()

public:
	AMainCameraPlayer();


	UPROPERTY(EditAnywhere, Category = "GhostMESH");
	UMaterialInterface* CanBeBuiltMaterial;
	UPROPERTY(EditAnywhere, Category = "GhostMESH");
	UMaterialInterface* CannotBeBuiltMaterial;

	UPROPERTY(EditAnywhere);
	/// <summary>
	/// Movement Speed of "Camera Player"
	/// </summary>
	float Speed = 100;
	UPROPERTY(EditAnywhere);
	/// <summary>
	/// This is Distance to snap one block to another
	/// </summary>
	float DistanceToSnap = 70;
	UPROPERTY(EditAnywhere);
	/// <summary>
	/// This is multiplier of Z movement distance.
	/// </summary>
	float UpDownSpeed = 50;
	UPROPERTY(EditAnywhere);
	/// <summary>
	/// This is grid size of blocks snapping
	/// </summary>
	float GridSize = 100;

	UPROPERTY(EditAnywhere, Category = "Blocks")
	uint32 BlockID = 0;
	UPROPERTY(EditAnywhere, Category = "Blocks")
	/// <summary>
	/// This is Actor That represents blocks.
	/// </summary>
	TArray<TSubclassOf<AActor>> Blocks;

	UPROPERTY(EditAnywhere, Category = "Blocks ghosts")
	/// <summary>
	/// Ghost block to spawn. I gonna rework this because, it's should use ActorToSpawn and should cut all functionalities then just use GFX.
	/// </summary>
	TSubclassOf<AActor> GhostToSpawn;

	UPROPERTY(EditAnywhere)
	FHitResult HitResult;
	UPROPERTY(EditAnywhere)
	FVector SurfacePoint;
	UPROPERTY(EditAnywhere)
	float cachedSpeed;
	UPROPERTY(EditAnywhere)
	AActor* Ghost;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* GhostMesh;
	UPROPERTY(EditAnywhere)
	APlayerController* PlayerController;
	UPROPERTY(EditAnywhere)
	class ANuclearForgeGameMode* GameMode;
	UPROPERTY(EditAnywhere)
	AActor* LastPlacedBlock;
	UPROPERTY(EditAnywhere)
	float DeltaTime;
	UPROPERTY(EditAnywhere)
	float CameraPanSpeed= 20;
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	void MovementForward(float AxisValue);
	void MovementSide(float AxisValue);
	void CameraPan(float axis);
	void IncreseSpeed(float value);
	void MoveUpDown(float value);
	void PlaceObject();
	void ConnectIfPossible(AActor* actor);
	void ChagneGhost(UClass* ghost);
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
	FVector SnapPosition(FVector& pos) {
		FVector position;
		position.X = FMath::Floor(pos.X / GridSize) * GridSize;
		position.Y = FMath::Floor(pos.Y / GridSize) * GridSize;
		position.Z = pos.Z;//FMath::Floor(pos.Z / 100.0f) * 100.0f;
		return position;
	}

};
