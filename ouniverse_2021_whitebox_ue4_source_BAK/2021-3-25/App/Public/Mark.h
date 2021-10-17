// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mark.generated.h"


class UStaticMeshComponent;
class UArrowComponent;

UCLASS()
class APP_API ARef : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARef();

};


UCLASS()
class APP_API ARefTransform : public ARef
{
	GENERATED_BODY()

public:

	ARefTransform();

#if WITH_EDITORONLY_DATA
	/** Component shown in the editor only to indicate character facing */

	UPROPERTY(Category = Ref, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Marker;
	
	UPROPERTY()
	UArrowComponent* ArrowComponent;

#endif

	//TArray<AActor*> PlaceActors();
};
