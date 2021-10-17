// Fill out your copyright notice in the Description page of Project Settings.


#include "Ref.h"
#include "Data/DataD.h"
#include "App/DataLib.h"

// Sets default values
ARef::ARef()
{
	TestString = NULL;

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ARef::PostLoad()
{
	Super::PostLoad();

	TestString = NULL;

	if (DataLibC::Get()->TryData(PackKey, DataKey, TestString))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TestString->I().ToFString());
	}
}

// Called when the game starts or when spawned
void ARef::BeginPlay()
{
	Super::BeginPlay();

	if(TestString != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TestString->I().ToFString());
	}
}

// Called every frame
void ARef::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}