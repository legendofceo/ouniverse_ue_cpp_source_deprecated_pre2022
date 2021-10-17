// Fill out your copyright notice in the Description page of Project Settings.


#include "Exec.h"
//#include "WorldProtocol.h"
#include "../Pro/Title/TitlePro.h"
#include "../Pro/OmniPro.h"
#include "../Pro/PausePro.h"

namespace GlobalSingleton
{
	UExec* gExec;
}

UExec* UExec::Get()
{
	return GlobalSingleton::gExec;
}

UExec* UExec::Create()
{
	UExec* Obj = NewObject<UExec>();
	GlobalSingleton::gExec = Obj;
	return Obj;
}

UExec::UExec()
{
	OmniPro_ = UOmniPro::Create();
	PausePro_ = UPausePro::Create();
	TitlePro_ = UTitlePro::Create();
}

void UExec::Start()
{
	OmniPro_->Start();
	PausePro_->Start();
	TitlePro_->Start();
}

void UExec::BTN(StrokeC* SE)
{
	if(PausePro_->IsActive())
	{

	}
	
	/**
	switch (SE->GetCode()) {
	case StrokeC::JOY_LookUD:
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("JOY UP."));
		break;
	case StrokeC::JOY_LookDD:
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("JOY DOWN."));
		break;
	case StrokeC::JOY_LookLD:
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("JOY LEFT."));
		break;
	case StrokeC::JOY_LookRD:
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("JOY RIGHT."));

		break;
	}
	*/

	switch (Focus_) {
	case Focus::Title:
		TitlePro_->BTN(SE);
		break;

	}

	if (SE->IsUnhandled())
	{
		switch (SE->GetCode()) {
		case StrokeC::JOY_StartD:
			PausePro_->PauseKey();
			break;
		}

	}
}