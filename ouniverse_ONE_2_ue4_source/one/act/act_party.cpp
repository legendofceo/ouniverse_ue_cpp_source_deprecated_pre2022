// Fill out your copyright notice in the Description page of Project Settings.



#include "act_party.h"
#include "../com/com_marker.h"


AActParty::AActParty()
{

	Origin = CreateDefaultSubobject<UComMarker>(TEXT("MarkerOrigin"));
	Origin->SetupAttachment(RootComponent);

	P1 = CreateDefaultSubobject<UComMarker>(TEXT("MarkerP1"));
	P1->SetupAttachment(Origin);

	P2 = CreateDefaultSubobject<UComMarker>(TEXT("MarkerP2"));
	P2->SetupAttachment(Origin);

	P3 = CreateDefaultSubobject<UComMarker>(TEXT("MarkerP3"));
	P3->SetupAttachment(Origin);

}

/**
void AActParty::OnConstruction(const FTransform& Transform)
{


	Super::OnConstruction(Transform);

#if WITH_EDITOR
	MeshP1->SetRelativeTransform(P1);
	MeshP2->SetRelativeTransform(P2);
	MeshP3->SetRelativeTransform(P3);
#endif

}
*/

void AActParty::BeginPlay()
{
	Super::BeginPlay();

}


void AActParty::Assume()
{

}