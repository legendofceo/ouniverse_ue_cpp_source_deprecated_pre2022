// Fill out your copyright notice in the Description page of Project Settings.

#include "TitleCreditsPro.h"
#include "../../System/Scope.h"
#include "../../System/Reg.h"
#include "../../System/Major.h"
#include "../../System/Ui.h"

void UTitleCreditsWin::NativeConstruct()
{
	Super::NativeConstruct();
}

UTitleCreditsPro* UTitleCreditsPro::Create()
{
	UTitleCreditsPro* Obj = NewObject<UTitleCreditsPro>();
	return Obj;
}

void UTitleCreditsPro::Link()
{

}


void UTitleCreditsPro::BTN(StrokeC* SE)
{

}