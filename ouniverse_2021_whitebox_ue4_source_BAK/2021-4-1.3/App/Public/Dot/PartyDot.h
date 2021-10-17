// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PartyDot.generated.h"

/**
 * RefParty is an actor reference used to place the party at a point in 3D space.
 * It has a visual representation while in editor, but servers just as a FTransform
 * with methods to place the party, in the runtime game.
 */

UCLASS()
class APP_API APartyDot : public AActor
{
	GENERATED_BODY()
	
public:	
	
	APartyDot();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Go Here"))
	void GoHere();
};
