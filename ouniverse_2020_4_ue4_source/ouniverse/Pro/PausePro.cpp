// Fill out your copyright notice in the Description page of Project Settings.

#include "PausePro.h"
#include "../System/Scope.h"
#include "../System/Reg.h"
#include "../System/Major.h"
#include "../System/Ui.h"

void UPauseWin::NativeConstruct()
{
	Super::NativeConstruct();
}

void UPauseWin::BeginPause()
{

}




UPausePro* UPausePro::Create()
{
	UPausePro* Obj = NewObject<UPausePro>();
	Obj->Init();
	return Obj;
}

void UPausePro::Init()
{
	Active = false;
}
void UPausePro::Start()
{
	Win_ = CreateWidget<UPauseWin>(ScopeC::World(), UReg::Get()->PauseWin_);
	
}

void UPausePro::PauseKey()
{
	if (IsActive())
	{
		Active = false;
		Win_->RemoveFromViewport();
	}
	else
	{
		Active = true;
		UMajor::Get()->Ui()->ToViewport(Win_);
		Win_->BeginPause();
	}
}

bool UPausePro::IsActive()
{
	return Active;
}