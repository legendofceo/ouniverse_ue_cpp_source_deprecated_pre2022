// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "form_f.h"
#include "../sys/area.h"

class Cell_F;

class Area_F : public Form_F
{

public:

	Area_F() {};
	virtual int FormType() override { return UFormType::Area; };

	virtual int FromJson(JsonS* J, FLogger* Log) override;
	virtual JsonS* ToJson(JsonS* JSon) override;
	TSoftClassPtr<AArea> ClassOverride;
	Cell_F* DefaultCell;

};