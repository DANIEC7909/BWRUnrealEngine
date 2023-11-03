// Fill out your copyright notice in the Description page of Project Settings.


#include "Transportable.h"

// Sets default values
ATransportable::ATransportable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
PrimaryActorTick.bCanEverTick = true;

}

void ATransportable::TransportProduct()
{
    if (Outlet!=nullptr) {
        if (CurrentTransportTime > TransportationTreshold)
        {
            if (Amount > 0)
            {
                Amount--;
                Outlet->Amount++;
            }
            CurrentTransportTime = 0;
        }
    }
}


