// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SnapPoint.h"
#include "GameFramework/Actor.h"
#include "Transportable.generated.h"

UCLASS()
class NUCLEARFORGE_API ATransportable : public AActor
{
	GENERATED_BODY()
	
public:	
	ATransportable();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TransportationTreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentTransportTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Amount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TransportAmount=5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 PresureDrop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Pressure;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Temperature;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TemperatureDrop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ATransportable* Outlet;
	UPROPERTY(EditAnywhere)
	FComponentReference USnapPointReference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USnapPoint* OutletSnapPoint;
protected:


public:	
	void TransportProduct(float DeltaTime);
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
