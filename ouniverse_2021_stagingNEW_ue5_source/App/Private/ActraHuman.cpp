// Fill out your copyright notice in the Description page of Project Settings.


#include "ActraHuman.h"
#include "KeywordComponent.h"
#include "EquipmentComponent.h"
#include "BodyComponent.h"
#include "HeadComponent.h"

// Sets default values
AActraHuman::AActraHuman()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	KeywordComponent = CreateDefaultSubobject<UKeywordComponent>(TEXT("KeywordComponent"));
	EquipmentComponent = CreateDefaultSubobject<UEquipmentComponent>(TEXT("EquipmentComponent"));
	EquipmentComponent->Init(50);
}

// Called when the game starts or when spawned
void AActraHuman::BeginPlay()
{
	Super::BeginPlay();

	BodyComponent->Init();
	HeadComponent->Init();

}

// Called every frame
void AActraHuman::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}