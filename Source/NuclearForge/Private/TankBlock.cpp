// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBlock.h"

ATankBlock::ATankBlock()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATankBlock::BeginPlay()
{
	Super::BeginPlay();
}

void ATankBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TransportProduct(DeltaTime);
}
