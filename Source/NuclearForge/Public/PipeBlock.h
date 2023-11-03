// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Transportable.h"
#include "PipeBlock.generated.h"

/**
 * 
 */
UCLASS()
class NUCLEARFORGE_API APipeBlock : public ATransportable
{
	GENERATED_BODY()
public:
	APipeBlock();
private:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
};
