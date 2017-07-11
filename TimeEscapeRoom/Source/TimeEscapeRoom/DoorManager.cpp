// Fill out your copyright notice in the Description page of Project Settings.

#include "TimeEscapeRoom.h"
#include "DoorManager.h"


// Sets default values for this component's properties
UDoorManager::UDoorManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorManager::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	if (!PressurePlate){
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName())
	}
}


// Called every frame
void UDoorManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
		
	// Poll the Trigger Volume
	if (isSomeActorOnPlate()) OnOpen.Broadcast();
	else OnClose.Broadcast();
}

bool UDoorManager::isSomeActorOnPlate()
{
	if (!PressurePlate) { return false; }
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	int32 numActors = 0;

	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	
	// TODO it should be something like count(array) to get the size, not using a for
	for (const auto& Actor : OverlappingActors)
	{
		numActors++;
	}

	if (numActors > 0) return true;
	return false;
}

