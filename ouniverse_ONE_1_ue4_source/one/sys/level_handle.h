// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "UObject/Object.h"
#include "Engine/LevelStreamingDynamic.h"
#include "UObject/SoftObjectPtr.h"
#include "level_handle.generated.h"

class ALevelStreamed;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FLevelCommandOutputDel, FName, ID, FName, Command, FName, Relay);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLevelCommandInputDel, FName, Command, FName, Relay);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProStreamedDel, FName, ID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProUnstreamedDel, FName, ID);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FProOpenDel, FName, ID, FName, Relay);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FProCloseDel, FName, ID, FName, Relay);

UCLASS(BlueprintType)
class ULevelHandle : public UObject
{

	GENERATED_BODY()

public:

	ULevelHandle();
	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	FName ID;


	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldCTX", ShowWorldContextPin))
	static ULevelHandle* CreateLevelHandle(TSubclassOf<ULevelHandle> InClass, TSoftObjectPtr<UWorld> InSoftLevel, FName InID, AProtocol_P* InOwningProtocol, UObject* WorldCTX);

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	ULevelStreamingDynamic* StreamedDynamic;

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	ALevelStreamed* StreamedLevel;

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	bool bLoaded;

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UWorld> SoftLevel;

	UPROPERTY(Category = "1 Details", VisibleAnywhere, BlueprintReadOnly)
	AProtocol_P* OwningProtocol;

	UFUNCTION(BlueprintCallable)
	void Stream();
	UFUNCTION(BlueprintCallable)
	void Unstream();

	UFUNCTION()
	void LevelStreamedComplete();
	UFUNCTION()
	void LevelUnstreamedComplete();




	UFUNCTION(BlueprintCallable)
	void InputCommand();

	UPROPERTY(BlueprintAssignable)
	FLevelCommandOutputDel OnProtocolCommandOutput;

	UPROPERTY(BlueprintAssignable)
	FLevelCommandInputDel OnProtocolCommandInput;

	UPROPERTY(BlueprintAssignable)
	FProStreamedDel OnLevelStreamed;

	UPROPERTY(BlueprintAssignable)
	FProUnstreamedDel OnLevelUnstreamed;

	UPROPERTY(BlueprintAssignable)
	FProOpenDel OnLevelOpen;

	UPROPERTY(BlueprintAssignable)
	FProCloseDel OnLevelClose;

};