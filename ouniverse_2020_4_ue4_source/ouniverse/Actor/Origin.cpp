// Fill out your copyright notice in the Description page of Project Settings.



#include "Origin.h"
#include "../Component/EditorMarker.h"


AOriginParty::AOriginParty()
{

#if WITH_EDITOR
	EdMarker0 = CreateDefaultSubobject<UEditorMarker>(TEXT("EdFx0"));
	EdMarker0->SetupAttachment(RootComponent);
#endif

}

/**
void AOriginParty::OnConstruction(const FTransform& Transform)
{


	Super::OnConstruction(Transform);

#if WITH_EDITOR
	//EdMarker0->SetRelativeTransform(Pos0);
	//EdMarker1->SetRelativeTransform(Pos1);
	//EdMarker2->SetRelativeTransform(Pos2);
#endif

}

void AOriginParty::BeginPlay()
{
	Super::BeginPlay();

}
*/