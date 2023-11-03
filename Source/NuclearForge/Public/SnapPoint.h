// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SnapPoint.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NUCLEARFORGE_API USnapPoint : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USnapPoint();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsOutlet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ATransportable* Parent;
protected:
	virtual void BeginPlay() override;
};
