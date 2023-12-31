// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Transportable.h"
#include "TankBlock.generated.h"

/**
 * 
 */
UCLASS()
class NUCLEARFORGE_API ATankBlock : public ATransportable
{
	GENERATED_BODY()
public:
	ATankBlock();
private:
	virtual void BeginPlay() override;
	//	virtual void OnConstruction() override;
public:
	virtual void Tick(float DeltaTime) override;

};
