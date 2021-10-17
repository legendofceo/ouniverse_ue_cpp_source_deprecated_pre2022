// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Delegate.h"
#include "Marshal/Marshal.h"
#include "Log.h"
#include "Lib.generated.h"


UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API ULib : public UObject
{
	GENERATED_BODY()
	
public:

	ULib();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString ID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bInit = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FMarshal Marshal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLogger Log;

	UPROPERTY(BlueprintAssignable)
	FDelegateObj OnInitComplete;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TSoftClassPtr<UObject>> SoftClasses;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#RegSCP"))
	void RegSCP(TSoftClassPtr<UObject> StoryClass);

	void SetID(FString ID);
	virtual void Init();
	
	
	virtual void PostInit();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@PostInit"))
	void PostInitBP();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@PreSS"))
	void PreSSBP();

	UFUNCTION()
	virtual void PostSS() {};
	
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@PostSS"))
	void PostSSBP();

	void Complete();

};