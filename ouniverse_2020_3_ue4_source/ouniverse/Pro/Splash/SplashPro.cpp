// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro/Splash/SplashPro.h"
#include "App/Reg.h"
#include "App/Scope.h"

#include "Ui/Splash/SplashLegalUi.h"
#include "Ui/Ui.h"

USplashPro* USplashPro::Create()
{
	USplashPro* Neu = NewObject<USplashPro>();
	return Neu;
}

void USplashPro::OpenPro(ProDockS* InDock)
{
	//Menu_ = Cast<USplashLegalUi>(CreateWidget<UUserWidget>(ScopeC::World(), UReg::Get()->SplashLegalUi.Default));
	//UUi::Get()->ToViewport(Menu_);
	//Menu_->Activate();
}