// Fill out your copyright notice in the Description page of Project Settings.


#include "App/Major.h"
#include "App/Scope.h"

namespace GlobalMajor
{
	UMajor* Object;
}



UMajor* UMajor::Create()
{
	UMajor* Neu = NewObject<UMajor>();
	GlobalMajor::Object = Neu;
	return Neu;
}

UUi* UMajor::Ui() { return GlobalMajor::Object->Ui_; };
UReg* UMajor::Reg() { return GlobalMajor::Object->Reg_; };
UMaestro* UMajor::Maestro() { return GlobalMajor::Object->Maestro_; };
AControl* UMajor::Control() { return GlobalMajor::Object->Control_; };
AServer* UMajor::Server() { return GlobalMajor::Object->Server_; };