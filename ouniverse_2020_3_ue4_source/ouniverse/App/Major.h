// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "Major.generated.h"


class UApp;
class UUi;
class UReg;
class UMaestro;
class AControl;
class AServer;
class UApp;

UCLASS()
class UMajor : public UObject
{
	GENERATED_BODY()

	friend UApp;

public:

	static UMajor* Create();

	static UUi* Ui();
	static UReg* Reg();
	static UMaestro* Maestro();
	static AControl* Control();
	static AServer* Server();

private:

	UPROPERTY()
	UUi* Ui_;
	UPROPERTY()
	UReg* Reg_;
	UPROPERTY()
	UMaestro* Maestro_;
	UPROPERTY()
	AControl* Control_;
	UPROPERTY()
	AServer* Server_;
};