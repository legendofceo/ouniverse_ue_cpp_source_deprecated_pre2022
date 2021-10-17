// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Delegate.h"
#include "Remote.generated.h"


UCLASS()
class APP_API ARemote: public AInfo
{
	GENERATED_BODY()
	
public:	

public:
	// Sets default values for this component's properties
	ARemote();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
