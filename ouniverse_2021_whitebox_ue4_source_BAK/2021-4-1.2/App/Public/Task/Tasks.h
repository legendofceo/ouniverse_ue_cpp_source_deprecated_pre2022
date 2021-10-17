// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Task/Task.h"
#include "Tasks.generated.h"


UCLASS()
class APP_API UTasks : public UTask
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TSet<UTask*> Tasks;

	void Add(UTask* AddTask);

	virtual void Go() override;

	UFUNCTION()
	void ReportCompleted(UTask* CompletedTask);

};