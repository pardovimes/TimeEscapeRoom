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
	if (false) OnOpen.Broadcast();
	else OnClose.Broadcast();
}

bool UDoorManager::isSomeActorOnPlate()
{
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!PressurePlate) { return false; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	
	//TODO find number of overlapping actors, if its greater than 0, return true, else false
	return false;
}

