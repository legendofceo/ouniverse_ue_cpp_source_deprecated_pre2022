// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro/Pro.h"
#include "Components/SceneComponent.h"

// Sets default values
APro::APro()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
}

// Called when the game starts or when spawned
void APro::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

