// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "form_f.h"
#include "head_f.generated.h"

class Head_F;

UCLASS(BlueprintType)
class UHead_F : public UForm_F
{
	GENERATED_BODY()

	UHead_F() {};

public:

	Head_F* HeadForm;
	void SetHead(Head_F* InForm);
	virtual void Save() override;
	virtual void New(UAtlas* InAtlas) override;


};

class Head_F : public Form_F
{

public:

	Head_F() {};
	virtual int FormType() override { return UFormType::Head; };

	virtual int FromJson(JsonS* J, FLogger* Log) override;

	virtual UForm_F* ToUObject() override;
};