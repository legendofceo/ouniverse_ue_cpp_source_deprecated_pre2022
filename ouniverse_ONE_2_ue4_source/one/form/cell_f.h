// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "form_f.h"
#include "common/softpath_link.h"
#include "../sys/Cell.h"

class Manifest_C;

class Cell_F : public Form_F
{

public:

	Cell_F() {};
	virtual int FormType() override { return UFormType::Cell; };

	virtual int FromJson(JsonS* J, FLogger* Log) override;
	virtual JsonS* ToJson(JsonS* JSon) override;
	SoftObjectPathLinkS<UWorld*> MapLink;
	ArrayC<Manifest_C*> Manifests;
	TSoftClassPtr<ACell> ClassOverride;

};