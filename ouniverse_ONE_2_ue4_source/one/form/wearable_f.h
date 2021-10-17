// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "form_f.h"
#include "common/softpath_link.h"
#include "wearable_f.generated.h"

class Wearable_F;

UCLASS(BlueprintType)
class UWearable_F : public UForm_F
{
	GENERATED_BODY()

		UWearable_F() {};

public:

	Wearable_F* WearableData;
	void SetWearable(Wearable_F* InForm);
	virtual void Save() override;
	virtual void New(UAtlas* InAtlas) override;


};


class Wearable_F : public Form_F
{

public:

	Wearable_F() {};
	virtual int FormType() override { return UFormType::Wearable; };

	virtual int FromJson(JsonS* J, FLogger* Log) override;
	virtual JsonS* ToJson(JsonS* JSon) override;
	SoftObjectPathLinkS<USkeletalMesh*> WearableMesh;

	virtual UForm_F* ToUObject() override;
};