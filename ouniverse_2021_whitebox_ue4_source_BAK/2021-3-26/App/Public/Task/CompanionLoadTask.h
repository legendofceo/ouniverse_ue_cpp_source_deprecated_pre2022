// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Task/Task.h"
#include "CompanionLoadTask.generated.h"


class UPlaythrough;
class UCompanion;

UCLASS()
class APP_API UCompanionLoadTask : public UTask
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCompanion* Companion;

	void Setup(UCompanion* InCompanion);

	virtual void Go() override;
};