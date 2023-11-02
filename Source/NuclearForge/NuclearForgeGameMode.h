// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MainCameraPlayer.h"
#include "SnapPoint.h" 
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NuclearForgeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class NUCLEARFORGE_API ANuclearForgeGameMode : public AGameModeBase
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite);
	TArray<USnapPoint*>SnapPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	AMainCameraPlayer* Player;
	UFUNCTION(BlueprintCallable)
	void AddSnappingPoint(USnapPoint * snapPoint);
};
