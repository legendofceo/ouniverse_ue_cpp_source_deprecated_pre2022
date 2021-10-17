// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Task/Task.h"
#include "CompanionLoadTask.generated.h"


class APlaythrough;
class ACompanion;

UCLASS()
class APP_API UCompanionLoadTask : public UTask
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ACompanion* Companion;

	void Setup(ACompanion* InCompanion);

	virtual void Go() override;
};