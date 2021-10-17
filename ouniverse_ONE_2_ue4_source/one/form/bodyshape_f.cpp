// Fill out your copyright notice in the Description page of Project Settings.

#include "bodyshape_f.h"
#include "common/form_link.h"
#include "wearable_f.h"


void UBodyshape_F::SetBodyshape(Bodyshape_F* InForm)
{
	SetForm(InForm);
	BodyshapeData = static_cast<Bodyshape_F*>(Form);
	NudeBust = BodyshapeData->NudeBust.CreateStruct();
	NudeLegs = BodyshapeData->NudeLegs.CreateStruct();
	NudeHands = BodyshapeData->NudeHands.CreateStruct();
	NudeFeet = BodyshapeData->NudeFeet.CreateStruct();
}

/**
void UBodyshape_F::GetBodyshape(FFormLink& NudeBust, FFormLink& NudeLegs, FFormLink& NudeHands, FFormLink& NudeFeet)
{
	NudeBust = BodyshapeData->NudeBust.CreateStruct();
	NudeLegs = BodyshapeData->NudeLegs.CreateStruct();
	NudeHands = BodyshapeData->NudeHands.CreateStruct();
	NudeFeet = BodyshapeData->NudeFeet.CreateStruct();

}
*/

void UBodyshape_F::Save()
{

	BodyshapeData->NudeBust.FromStruct(NudeBust);
	BodyshapeData->NudeLegs.FromStruct(NudeLegs);
	BodyshapeData->NudeHands.FromStruct(NudeHands);
	BodyshapeData->NudeFeet.FromStruct(NudeFeet);
	UForm_F::Save();
}

void UBodyshape_F::New(UAtlas* InAtlas)
{
	Bodyshape_F* NewData = new Bodyshape_F();
	SetupNew(NewData,InAtlas);
	SetBodyshape(NewData);
}


int Bodyshape_F::FromJson(JsonS* J, FLogger* Log)
{
	ID = J->String(DataKeys::ID);

	if (!NudeBust.FromJson(this, J, DataKeys::Bodyshape::NudeBust))
		Log->Write(PrintError("NudeBust"), ELogStatus::RequiredData);
	if (!NudeLegs.FromJson(this, J, DataKeys::Bodyshape::NudeLegs))
		Log->Write(PrintError("NudeLegs"), ELogStatus::RequiredData);
	if (!NudeHands.FromJson(this, J, DataKeys::Bodyshape::NudeHands))
		Log->Write(PrintError("NudeHands"), ELogStatus::RequiredData);
	if (!NudeFeet.FromJson(this, J, DataKeys::Bodyshape::NudeFeet))
		Log->Write(PrintError("NudeFeet"), ELogStatus::RequiredData);

	return DataReport_D::Approved;
}


JsonS* Bodyshape_F::ToJson(JsonS* J)
{
	Form_F::ToJson(J);
	J->Add(DataKeys::Bodyshape::NudeBust, NudeBust.ToJson(this));
	J->Add(DataKeys::Bodyshape::NudeLegs, NudeBust.ToJson(this));
	J->Add(DataKeys::Bodyshape::NudeHands, NudeHands.ToJson(this));
	J->Add(DataKeys::Bodyshape::NudeFeet, NudeFeet.ToJson(this));
	return J;
}


UForm_F* Bodyshape_F::ToUObject()
{
	UBodyshape_F* Form = NewObject<UBodyshape_F>();
	Form->SetBodyshape(this);
	return Form;
}