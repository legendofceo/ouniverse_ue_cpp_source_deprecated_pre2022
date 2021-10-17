// Fill out your copyright notice in the Description page of Project Settings.

#include "wearable_f.h"

void UWearable_F::SetWearable(Wearable_F* InForm)
{
	SetForm(InForm);
	WearableData = static_cast<Wearable_F*>(Form);
}

void UWearable_F::Save()
{
	UForm_F::Save();
}

void UWearable_F::New(UAtlas* InAtlas)
{
	Wearable_F* NewData = new Wearable_F();
	SetupNew(NewData, InAtlas);
	SetWearable(NewData);
}



int Wearable_F::FromJson(JsonS* J, FLogger* Log)
{
	WearableMesh.FromJson(this,J,DataKeys::Wearable::SkeletalMesh);
	return DataReport_D::Approved;
}

JsonS* Wearable_F::ToJson(JsonS* J)
{
	Form_F::ToJson(J);
	J->Add(DataKeys::Wearable::SkeletalMesh, WearableMesh.ToString());
	return J;
}

UForm_F* Wearable_F::ToUObject()
{
	UWearable_F* Form = NewObject<UWearable_F>();
	Form->SetWearable(this);
	return Form;
}