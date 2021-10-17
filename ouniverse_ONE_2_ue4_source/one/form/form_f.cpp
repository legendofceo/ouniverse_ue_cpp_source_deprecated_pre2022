// Fill out your copyright notice in the Description page of Project Settings.

#include "form_f.h"
#include "../sys/data_manager.h"
#include "../sys/atlas.h"


void UForm_F::SetForm(Form_F* InForm)
{
	Form = InForm;
	ID = FText::FromString(Form->ID);
	UID = Form->UID;
	FormType = InForm->FormType();
	Atlas = Form->Atlas;
}

void UForm_F::Save()
{
	Form->ID = ID.ToString();

	if (bNew)
	{
		Atlas->AddNewData(Form);
		bNew = false;
	}	
}

void UForm_F::New(UAtlas* InAtlas)
{
	Form_F* NewData = new Form_F();
	SetupNew(NewData,InAtlas);
	SetForm(NewData);
}

void UForm_F::SetupNew(Form_F* InForm, UAtlas* InAtlas)
{
	bNew = true;
	Form = InForm;
	Form->Atlas = InAtlas;
	Form->UID = Form->Atlas->NewUID();
}



bool UForm_F::IsFormTypeRelative()
{
	return false;
}

void UForm_F::Delete()
{
	delete Form;
}

UFormType* UForm_F::GetFormType()
{
	return UDataManager::Get()->GetFormType(FormType);

}










void Form_F::BaseData(JsonS* J, UAtlas* InAtlas, FLogger* Log)
{
	Atlas = InAtlas;
	UID = J->Int(DataKeys::UniversalNumber);
	ID = J->String(DataKeys::ID);
}

FString Form_F::Print()
{
	return FString::FromInt(Atlas->UID) + "." + FString::FromInt(UID);
}

JsonS Form_F::ToJson()
{
	JsonS J = JsonS();
	JsonS* JOut = ToJson(J);
	return JsonS(JOut);
}

JsonS* Form_F::ToJson(JsonS* J)
{
	J->Add(DataKeys::UniversalNumber, UID);
	J->Add(DataKeys::ID, ID);
	J->Add(DataKeys::FormType, FormType());
	return J;
}

int Form_F::FromJson(JsonS* J, FLogger* Log)
{
	return DataReport_D::Approved;
}

bool Form_F::IsRelative(int TypeID)
{
	if (FormType()== TypeID)
	{
		return true;
	}

	return false;
}


UForm_F* Form_F::ToUObject()
{
	UForm_F* Form = NewObject<UForm_F>();
	Form->SetForm(this);
	return Form;
}

FString Form_F::PrintError(FString Key)
{
	return Print() + " | " + " Data was not resolved: " + Key;
}

