// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Transportable.generated.h"

UCLASS()
class NUCLEARFORGE_API ATransportable : public AActor
{
	GENERATED_BODY()
	
public:	
	ATransportable();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Amount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Pressure;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ProductTemperature;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ATransportable* Outlet;

protected:


public:	
	

};
