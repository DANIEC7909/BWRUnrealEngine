// Fill out your copyright notice in the Description page of Project Settings.


#include "Transportable.h"
#include <Logging/StructuredLog.h>

// Sets default values
ATransportable::ATransportable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATransportable::TransportProduct(float DeltaTime)
{
	CurrentTransportTime += DeltaTime;
	if (Outlet != nullptr)
	{
		if (CurrentTransportTime > TransportationTreshold)
		{
			if (Amount > 0 && (Amount-TransportAmount)>0)
			{
				Amount-= TransportAmount;
				Outlet->Amount+= TransportAmount;
			}
			CurrentTransportTime = 0;
		}
		Outlet->Temperature = Temperature - TemperatureDrop;
	}
}

void ATransportable::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	
	
	
	//UE_LOG(LogTemp, Log,TEXT("Testing"), *FString(PropertyChangedEvent.GetPropertyName().ToString()));
}


