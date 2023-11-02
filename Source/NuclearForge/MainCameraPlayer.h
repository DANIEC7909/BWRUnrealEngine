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
	void MovementForward(float AxisValue);
	void MovementSide(float AxisValue);
	void IncreseSpeed(float value);
	void MoveUpDown(float value);
	void PlaceObject();
	void ChagneGhost(UClass* ghost);
	UPROPERTY(EditAnywhere, Category = "GhostMESH");
	UMaterialInterface* CanBeBuiltMaterial;
	UPROPERTY(EditAnywhere, Category = "GhostMESH");
	UMaterialInterface* CannotBeBuiltMaterial;
	UPROPERTY(EditAnywhere);
	float Speed=100;
	UPROPERTY(EditAnywhere);
	float UpDownSpeed = 50;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPROPERTY(EditAnywhere, Category = "Testing")
	TSubclassOf<AActor> ActorToSpawn;
	FHitResult HitResult;
	FVector SurfacePoint;
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
