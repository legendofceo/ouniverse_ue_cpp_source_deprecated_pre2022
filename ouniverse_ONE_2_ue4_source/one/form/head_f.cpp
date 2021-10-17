// Fill out your copyright notice in the Description page of Project Settings.

#include "head_f.h"



void UHead_F::SetHead(Head_F* InForm)
{
	SetForm(InForm);
	HeadForm = static_cast<Head_F*>(Form);
}

void UHead_F::Save()
{
	Super::Save();
}

void UHead_F::New(UAtlas* InAtlas)
{
	Head_F* NewForm = new Head_F();
	SetupNew(NewForm, InAtlas);
	SetHead(NewForm);
}



int Head_F::FromJson(JsonS* J, FLogger* Log)
{
	return DataReport_D::Approved;
}

UForm_F* Head_F::ToUObject()
{
	UForm_F* Form = NewObject<UHead_F>();
	Form->SetForm(this);
	return Form;
}