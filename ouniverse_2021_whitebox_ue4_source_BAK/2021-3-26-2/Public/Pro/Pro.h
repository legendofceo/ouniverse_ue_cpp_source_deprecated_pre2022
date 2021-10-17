// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Pro.generated.h"

class USceneComponent;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APP_API UPro : public UActorComponent
{
	GENERATED_BODY()
	
public:	

	UPro();


protected:

	virtual void BeginPlay() override;


};
