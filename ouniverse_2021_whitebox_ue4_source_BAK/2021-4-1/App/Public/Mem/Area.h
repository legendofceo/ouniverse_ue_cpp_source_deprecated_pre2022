// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mem/Mem.h"
#include "AreaAddress.h"
#include "Delegate.h"
#include "Mem/Zone.h"
#include "Type/Map.h"
#include "Area.generated.h"

/**
 * 
 */

struct FLogger;
struct FZone;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateArea, UArea*, Area);

UCLASS(Abstract,BlueprintType,Blueprintable)
class APP_API UArea : public UMem
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName ID;

	FLogger* Log;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Key;


	void Init(FLogger* InLog);
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Init"))
	void InitBP();

	/**
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Add SoftServe"))
	void AddSoftServe(TSoftClassPtr<UObject> SCP);


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Add SoftServe"))
	void AddSoftServe(TSoftClassPtr<UObject> SCP);

	UFUNCTION()
	void PostSS(USoftServe* SS);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@PreSoftServe"))
	void PreSoftServeBP();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@PostSS"))
	void PostSSBP();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USoftServe* SoftServe;

	*/

	UPROPERTY(BlueprintAssignable)
	FDelegateArea OnInitComplete;




	MapC<FName, FZone*> Zones;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#RegZone"))
	void RegZone(UPARAM(ref) FZone& Zone);


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#Load Zone"))
	void LoadZone(UPARAM(ref) FZone& Zone);

	FZone* ActiveZone;

	void Enter(FAddress InAddress);
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@Enter"))
	void EnterBP(FAddress InAddress);

	void Unload() {};

	UPROPERTY(BlueprintAssignable)
	FDelegate OnLoaded;
	UPROPERTY(BlueprintAssignable)
	FDelegate OnUnloaded;


};
