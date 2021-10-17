// Fill out your copyright notice in the Description page of Project Settings.

#include "form_type.h"
#include "translation_manager.h"
#include "data_manager.h"


UFormType* UFormType::Create(FFormTypeRow* Row)
{
	UFormType* NewForm = NewObject<UFormType>();
	NewForm->UID = Row->UID;
	NewForm->ParentUID = Row->ParentUID;
	NewForm->NameKey = Row->NameKey;
	NewForm->Abbreviation = Row->Abbreviation;
	NewForm->Icon = Row->Icon;
	NewForm->Color = Row->Color;
	NewForm->FormPage = Row->FormPage;
	NewForm->FormObject = Row->FormObject;
	NewForm->bAbstract = Row->bAbstract;
	NewForm->bMapPlaceable = Row->bMapPlaceable;
	NewForm->Translate();
	return NewForm;
}


void UFormType::Translate()
{
	Name = UTranslationManager::Translate(NameKey);
}


void UFormType::SetParent()
{
	if (ParentUID != -1)
	{
		Parent = UDataManager::Get()->GetFormType(ParentUID);
	}
	else
	{
		Parent = nullptr;
	}

}

bool UFormType::IsRelative(UFormType* InFormType)
{
	if (InFormType == this)
	{
		return true;
	}
	else
	{
		if (Parent == nullptr)
		{
			return false;
		}
		else
		{
			return Parent->IsRelative(InFormType);
		}
	}
}