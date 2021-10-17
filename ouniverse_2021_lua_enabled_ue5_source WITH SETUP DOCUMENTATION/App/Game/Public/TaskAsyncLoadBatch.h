// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Task.h"
#include "TaskAsyncLoadBatch.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTaskAsyncLoadBatchReplyInt, int, TaskInt);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTaskAsyncLoadBatchReplyName, FName, TaskName);

UENUM(BlueprintType)
enum class EValidNull : uint8
{
	Valid,
	Null,
};


UCLASS(Blueprintable,BlueprintType)
class APP_API UTaskAsyncLoadBatch : public UTask
{
	GENERATED_BODY()

public:

	UTaskAsyncLoadBatch();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TSoftClassPtr<UObject>> SoftClasses;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TSoftObjectPtr<UObject>> SoftObjects;

	void Add(TSoftClassPtr<UObject> SCP);

	void Add(TSoftObjectPtr<UObject> SOP);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#AddSoftClass"))
	void AddSoftClassBP(TSoftClassPtr<UObject> SCP, UTaskAsyncLoadBatch*& R);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#AddSoftObject"))
	void AddSoftObjectBP(TSoftObjectPtr<UObject> SOP, UTaskAsyncLoadBatch*& R);

	virtual void RunTaskOverride() override;

	bool HasNull();
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "#HasNull?", ExpandEnumAsExecs = Execs))
	void HasNullBP(UTaskAsyncLoadBatch*& R, EValidNull& Execs);

	void AsyncLoadComplete();


};