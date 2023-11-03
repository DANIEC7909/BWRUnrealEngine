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
	int Amount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PresureDrop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Pressure;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Temperature;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TemperatureDrop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ATransportable* Outlet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USnapPoint* OutletSnapPoint;
protected:


public:	
	void TransportProduct();

};
