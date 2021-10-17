// Fill out your copyright notice in the Description page of Project Settings.


#include "Mark.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"

// Sets default values
ARef::ARef()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

ARefTransform::ARefTransform()
{
	PrimaryActorTick.bCanEverTick = false;



#if WITH_EDITORONLY_DATA

	Marker = CreateEditorOnlyDefaultSubobject<UStaticMeshComponent>(TEXT("Marker"));
	if (Marker)
	{
		//ArrowComponent->ArrowColor = FColor(150, 200, 255);
		//ArrowComponent->bTreatAsASprite = true;
		//ArrowComponent->SpriteInfo.Category = ConstructorStatics.ID_Characters;
		//ArrowComponent->SpriteInfo.DisplayName = ConstructorStatics.NAME_Characters;
		//ArrowComponent->SetupAttachment(CapsuleComponent);
		//ArrowComponent->bIsScreenSizeScaled = true;
		Marker->SetupAttachment(GetRootComponent());
	}

	ArrowComponent = CreateEditorOnlyDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	if (ArrowComponent)
	{
		ArrowComponent->ArrowColor = FColor(150, 200, 255);
		ArrowComponent->bTreatAsASprite = true;
		//ArrowComponent->SpriteInfo.Category = ConstructorStatics.ID_Characters;
		//ArrowComponent->SpriteInfo.DisplayName = ConstructorStatics.NAME_Characters;
		ArrowComponent->SetupAttachment(GetRootComponent());
		ArrowComponent->bIsScreenSizeScaled = true;
	}
#endif // WITH_EDITORONLY_DATA

}