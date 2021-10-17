// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nexus.h"
#include "AreaAddress.h"
#include "AreaMng.generated.h"

struct FZone;

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API AAreaMng : public ANexus
{
	GENERATED_BODY()
	

public:

	AAreaMng();


	static AAreaMng* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":AreaMng"))
	static void GetAreaMngBP(AAreaMng*& AreaMng);

	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FAreaAddress PendingAreaAddress;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FAreaAddress AreaAddress;


	void ChangeArea(UArea* NextArea, FAddress NextAddress);

	UFUNCTION()
	void AreaUnloaded();


	FZone* ActiveZone;

	void LoadZone(FZone* Zone);

};
