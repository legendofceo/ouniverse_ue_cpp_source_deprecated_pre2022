// Fill out your copyright notice in the Description page of Project Settings.

#include "OmniPro.h"
#include "../System/Scope.h"
#include "../System/Reg.h"
#include "../System/Major.h"
#include "../System/Ui.h"

void UOmniWin::NativeConstruct()
{
	Super::NativeConstruct();
}

UOmniPro* UOmniPro::Create()
{
	UOmniPro* Obj = NewObject<UOmniPro>();
	return Obj;
}

void UOmniPro::Start()
{
	Win_ = CreateWidget<UOmniWin>(ScopeC::World(), UReg::Get()->OmniWin_);
	UMajor::Get()->Ui()->ToViewport(Win_);
}