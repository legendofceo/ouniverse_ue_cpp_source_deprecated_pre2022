// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mng/Mng.h"
#include "AreaAddress.h"
#include "AreaMng.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API AAreaMng : public AManagerActor
{
	GENERATED_BODY()
	

public:

	AAreaMng();


	static AAreaMng* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = ":AreaMng"))
	static void GetAreaMngBP(AAreaMng*& AreaMng);

	virtual void BeginPlay() override;


	/** Address of pending Area stored during asynchronous loading. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FAreaAddress PendingAreaAddress;

	/** Current Area Address for debugging. */
	FAreaAddress AreaAddress;

	/** Current active Area. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UArea* Area;

	void ChangeArea(FAreaAddress NextArea);

	UFUNCTION()
	void AreaUnloaded();

	UFUNCTION()
	void LoadNextArea();

};
