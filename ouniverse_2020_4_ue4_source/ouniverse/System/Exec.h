// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Stroke.h"
#include "Input.h"
#include "Exec.generated.h"

class UPausePro;
class UOmniPro;
class UTitlePro;
class UGamePro;

UCLASS(Abstract, Blueprintable)
class UExec : public UObject, public InputC
{

	GENERATED_BODY()
public:


	UExec();

	enum Focus
	{
		Title,
	};

	int Focus_;

	static UExec* Get();
	static UExec* Create();

	UPROPERTY()
	UOmniPro* OmniPro_;
	UPROPERTY()
	UPausePro* PausePro_;
	UPROPERTY()
	UTitlePro* TitlePro_;

	UPROPERTY()
	UGamePro* GamePro_;

	void Start();

	void AXIS(StrokeC* S) override {};
	void BTN(StrokeC* S) override;


};