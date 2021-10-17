// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Protocol.h"
#include "../System/Input.h"
#include "../Ui/UiBase.h"
#include "PausePro.generated.h"




UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UPauseWin : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void BeginPause();
};

UCLASS()
class OUNIVERSE_API UPausePro : public UProtocol, public InputC
{
	GENERATED_BODY()

public:

	UPausePro() {};

	static UPausePro* Create();

	void Init();

	void Start();

	void PauseKey();

	UPROPERTY()
	UPauseWin* Win_;	

	bool IsActive();

private:

	bool Active;
};