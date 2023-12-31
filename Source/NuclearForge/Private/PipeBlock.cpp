// Fill out your copyright notice in the Description page of Project Settings.


#include "PipeBlock.h"
#include "DrawDebugHelpers.h"
APipeBlock::APipeBlock()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APipeBlock::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(53, 10, FColor::Blue ,FString(ActorInstanceGuid.ToString()));

}

//void APipeBlock::OnConstruction()
//{
//	GEngine->AddOnScreenDebugMessage(0, 10, FColor::Emerald, TEXT("oncost"));
//
//}

void APipeBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//DrawDebugString(GetWorld(), GetActorLocation() + FVector(0, 0, 200), FString::FromInt(Amount));
	
	TransportProduct(DeltaTime);
}
