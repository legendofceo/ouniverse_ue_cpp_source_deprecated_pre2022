// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "Pro.generated.h"


class UPro;

struct ProDockS
{

public:

	ProDockS();

	UPro* Pending_;
	UPro* Active_;

	void Go(UPro* InPro);

};

UCLASS()
class OUNIVERSE_API UPro : public UObject
{
	GENERATED_BODY()


public:

	virtual void OpenPro(ProDockS* InDock) {};

	virtual bool OnStroke(const FFKey& InCommand) { return false; };

};