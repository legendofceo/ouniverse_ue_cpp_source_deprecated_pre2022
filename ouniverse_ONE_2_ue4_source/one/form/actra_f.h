// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "form_f.h"
#include "common/form_link.h"
#include "../act/actra_human.h"
#include "actra_f.generated.h"

class Bodyshape_F;
class Head_F;
class Actra_D;

UCLASS(BlueprintType)
class UActra_F : public UForm_F
{
	GENERATED_BODY()

	UActra_F() {};

public:

	Actra_D* ActraData;
	void SetForm(Actra_D* Input);
	virtual void Save() override;
	virtual void New(UAtlas* InAtlas) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FText FirstName;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FText  LastName;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Sex;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FFormLink Bodyshape;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FFormLink Head;

};


class Actra_D : public Form_F
{
public:

	Actra_D() {};
	virtual int FormType() override { return UFormType::Actra; };

	virtual int FromJson(JsonS* J, FLogger* Log) override;
	virtual JsonS* ToJson(JsonS* J) override;
	FString FirstName;
	FString LastName;
	int Birthday;
	int Sex;
	FormLinkS<Bodyshape_F*> Bodyshape;
	FormLinkS<Head_F*> Head;
	TSoftClassPtr<AActraHuman> ClassOverride;

	virtual UForm_F* ToUObject() override;

};