// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "form_f.h"
#include "Engine/SkeletalMesh.h"


class Fitting_F : public Form_F
{


public:

	Fitting_F() {};
	virtual int FormType() override { return UFormType::Fitting; };

	virtual int FromJson(JsonS* J, FLogger* Log) override;
	TMap<FString, TSoftClassPtr<USkeletalMesh>> BodyshapeMap;
};