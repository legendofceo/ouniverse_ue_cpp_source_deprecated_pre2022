// Fill out your copyright notice in the Description page of Project Settings.


#include "ico.h"
#include "../sys/ico_manager.h"

void UIco_U::NativeConstruct()
{
	Super::NativeConstruct();
}

void UIcoSlot_U::NativeConstruct()
{
	Super::NativeConstruct();
}

void UIcoSlot_U::SetIcoByID(int32 IconID)
{
	TSoftClassPtr<UIco_U> IcoClass = UIcoManager::Get()->FindOrDefault(IconID);
	SetIco(CreateWidget<UIco_U>(this, IcoClass.LoadSynchronous()));
}