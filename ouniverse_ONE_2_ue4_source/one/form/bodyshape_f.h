// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "form_f.h"
#include "bodyshape_f.generated.h"

class Wearable_F;
class Bodyshape_F;

UCLASS(BlueprintType)
class UBodyshape_F : public UForm_F
{
	GENERATED_BODY()

	UBodyshape_F() {};

public:

	Bodyshape_F* BodyshapeData;
	void SetBodyshape(Bodyshape_F* Input);	
	virtual void Save() override;
	virtual void New(UAtlas* InAtlas) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FFormLink NudeBust;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FFormLink NudeLegs;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FFormLink NudeHands;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FFormLink NudeFeet;


};

class Bodyshape_F : public Form_F
{

public:

	Bodyshape_F() {};
	virtual int FormType() override { return UFormType::Bodyshape; };
	virtual int FromJson(JsonS* J, FLogger* Log) override;
	virtual JsonS* ToJson(JsonS* JSon) override;

	FormLinkS<Wearable_F*> NudeBust;
	FormLinkS<Wearable_F*> NudeLegs;
	FormLinkS<Wearable_F*> NudeHands;
	FormLinkS<Wearable_F*> NudeFeet;

	virtual UForm_F* ToUObject() override;

};