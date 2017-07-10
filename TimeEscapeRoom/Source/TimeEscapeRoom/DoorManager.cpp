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

	UE_LOG(LogTemp, Warning, TEXT("%f DeltaTime"), DeltaTime)

	// Poll the Trigger Volume
	if (true)
	{
		OnOpen.Broadcast();
	}
	else
	{
		OnClose.Broadcast();
	}
}

