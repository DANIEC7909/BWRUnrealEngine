// Fill out your copyright notice in the Description page of Project Settings.


#include "PipeBlock.h"

APipeBlock::APipeBlock()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APipeBlock::BeginPlay()
{
	Super::BeginPlay();

}

void APipeBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
