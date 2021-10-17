// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
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
	
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@PreAsync"))
	void PreAsyncBP();

	UFUNCTION()
	virtual void PostAsync() {};
	
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "@PostAsync"))
	void PostAsyncBP();

	void Complete();

};