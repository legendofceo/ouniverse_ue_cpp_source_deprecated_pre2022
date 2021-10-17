// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Area.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAreaDelegate);

class ULevelStreamingDynamic;

UCLASS(Abstract,BlueprintType,Blueprintable)
class APP_API UArea : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool AutoMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UWorld> AutoMapClass;

	void Load(FName Address);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Load"))
	void DoLoadBP(FName Address);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Load Complete"))
	void LoadComplete();

	void Unload();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Unload Complete"))
	void UnloadComplete();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ULevelStreamingDynamic* StreamedDynamic;

	/** Begins streaming a level from a SoftPointer. */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Load Map"))
	void DoLoadMap(TSoftObjectPtr<UWorld> Map);

	void MapLoaded();

	UPROPERTY(BlueprintAssignable)
	FAreaDelegate OnLoaded;

	UPROPERTY(BlueprintAssignable)
	FAreaDelegate OnUnloaded;

};
