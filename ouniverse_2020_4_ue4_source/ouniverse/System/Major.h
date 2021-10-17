// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Major.generated.h"

class ScopeC;
class AControlUE;
class UViewportUE;
class AHudUE;
class PartyC;
class BootC;
class UData;
class UExec;
class USpace;
class ULocalization;
class UUi;
class UDirector;

UCLASS()
class OUNIVERSE_API UMajor : public UObject
{
	GENERATED_BODY()

	friend BootC;

public:

	UMajor() {};
	static UMajor* Get();
	static UMajor* Create();

	UObject*			WorldContext();
	AHudUE*				Hud();
	AControlUE*			Control();
	ScopeC*				Scope();
	UViewportUE*		Viewport();
	PartyC*				Party();
	UData*				Data();
	USpace*				Space();
	UUi*				Ui();
	UExec*				Exec();
	ULocalization*		Localization();
	UDirector*			Director();

private:

	UObject*			WorldContext_;
	ScopeC*				Scope_;
	UViewportUE*		Viewport_;
	AHudUE*				Hud_;
	AControlUE*			Control_;
	PartyC*				Party_;
	UPROPERTY()
	UData*				Data_;
	UPROPERTY()
	USpace*				Space_;
	UPROPERTY()
	UUi*				Ui_;
	UPROPERTY()
	UExec*				Exec_;
	UPROPERTY()
	ULocalization*		Localization_;
	UPROPERTY()
	UDirector*			Director_;
};