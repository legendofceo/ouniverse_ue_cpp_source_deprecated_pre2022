// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Task.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTaskDelegate, UTask*, Task);


UCLASS(Abstract,Blueprintable,BlueprintType)
class APP_API UTask : public UObject
{
	GENERATED_BODY()

public:

	UTask();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool Completed = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName TaskContext;

	UFUNCTION(BlueprintCallable, category = Task, meta = (DisplayName = "#Run Task"))
	void RunTask(FName Context);

	virtual void RunTaskOverride();

	UFUNCTION()
	virtual void Complete();

	UPROPERTY(BlueprintAssignable)
	FTaskDelegate OnComplete;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	FName TaskKey;
};

UCLASS()
class APP_API UTaskMulti : public UTask
{
	GENERATED_BODY()

public:

	UTaskMulti();

	static UTaskMulti* New(UObject* Outer);

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TSet<UTask*> Tasks;

	void Add(UTask* AddTask);

	virtual void RunTaskOverride() override;

	UFUNCTION()
	void ReportCompleted(UTask* CompletedTask);

};