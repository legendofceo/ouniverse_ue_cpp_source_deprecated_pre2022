// Fill out your copyright notice in the Description page of Project Settings.

#include "actra_f.h"


void UActra_F::SetForm(Actra_D* InForm)
{
	Super::SetForm(InForm);
	ActraData = static_cast<Actra_D*>(Form);
	FirstName = FText::FromString(ActraData->FirstName);
	LastName = FText::FromString(ActraData->LastName);
	Sex = ActraData->Sex;
	Bodyshape = ActraData->Bodyshape.CreateStruct();
	Head = ActraData->Head.CreateStruct();


}

void UActra_F::Save()
{
	ActraData->FirstName = FirstName.ToString();
	ActraData->LastName = LastName.ToString();
	ActraData->Sex = Sex;
	ActraData->Bodyshape.FromStruct(Bodyshape);
	ActraData->Head.FromStruct(Head);
	Super::Save();
}

void UActra_F::New(UAtlas* InAtlas)
{
	Actra_D* NewData = new Actra_D();
	SetupNew(NewData, InAtlas);
	SetForm(NewData);
}








int Actra_D::FromJson(JsonS* J, FLogger* Log)
{
	J->TryString(FirstName,DataKeys::Actra::FirstName);
	J->TryString(LastName,DataKeys::Actra::LastName);
	J->TryInt(Sex,DataKeys::Actra::Sex);

	if(!Bodyshape.FromJson(this, J, DataKeys::Actra::Bodyshape))
		Log->Write(PrintError("Bodyshape"), ELogStatus::RequiredData);
	if (!Head.FromJson(this, J, DataKeys::Actra::Head))
		Log->Write(PrintError("Head"), ELogStatus::RequiredData);

	return DataReport_D::Approved;
}

JsonS* Actra_D::ToJson(JsonS* J)
{
	Form_F::ToJson(J);
	J->Add(DataKeys::Actra::FirstName, FirstName);
	J->Add(DataKeys::Actra::LastName, LastName);
	J->Add(DataKeys::Actra::Sex, Sex);
	J->Add(DataKeys::Actra::Bodyshape, Bodyshape.ToJson(this));
	J->Add(DataKeys::Actra::Head, Head.ToJson(this));

	return J;
}

UForm_F* Actra_D::ToUObject()
{
	UActra_F* Form = NewObject<UActra_F>();
	Form->SetForm(this);
	return Form;
}