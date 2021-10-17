// Fill out your copyright notice in the Description page of Project Settings.



#include "Major.h"
#include "ControlUE.h"
#include "Scope.h"
#include "HudUE.h"
#include "Party.h"
#include "Data.h"
#include "Exec.h"
#include "ViewportUE.h"
#include "Space.h"
#include "Ui.h"
#include "Localization.h"

namespace GlobalSingleton
{
	UMajor* gMajor;
}

UMajor* UMajor::Get()
{
	return GlobalSingleton::gMajor;
}

UMajor* UMajor::Create()
{
	UMajor* M = NewObject<UMajor>();
	GlobalSingleton::gMajor = M;
	return M;
}


UObject* UMajor::WorldContext()				{ return WorldContext_; }
ScopeC* UMajor::Scope()						{ return Scope_; }
AHudUE* UMajor::Hud()						{ return Hud_; }
PartyC* UMajor::Party()						{ return Party_; }
UData* UMajor::Data()						{ return Data_; }
USpace* UMajor::Space()						{ return Space_; }
UUi* UMajor::Ui()							{ return Ui_; }
UExec* UMajor::Exec()						{ return Exec_; }
UViewportUE* UMajor::Viewport()				{ return Viewport_; }
AControlUE* UMajor::Control()				{ return Control_; }
ULocalization* UMajor::Localization()		{ return Localization_; }
UDirector* UMajor::Director()				{ return Director_; }