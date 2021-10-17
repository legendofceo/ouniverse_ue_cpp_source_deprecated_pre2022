// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Statics.generated.h"

/**
 * 
 */
UCLASS()
class ONE_API UStatics : public UObject
{
	GENERATED_BODY()

public:
		static TArray<AActor*> GetAllActorsOnScreenInRadius(UObject* WorldContextObject, FVector Epicenter, float MaxRange, TArray<TEnumAsByte<EObjectTypeQuery>> CollisionQuery, UClass* FilteredClass, TArray<AActor*> IgnoreActors);

};



USTRUCT()
struct FActorAndScreenX
{
	GENERATED_BODY()


	UPROPERTY()
	float X;

	UPROPERTY()
	AActor* Actor;

public:

	FActorAndScreenX() {};
	FActorAndScreenX(float InX, AActor* InActor)
	{
		X = InX;
		Actor = InActor;
	}
};

struct FSortActorAndScreenX
{
	FSortActorAndScreenX() {};

	bool operator()(const FActorAndScreenX A, const FActorAndScreenX B) const
	{
		return A.X < B.X;
	}
};