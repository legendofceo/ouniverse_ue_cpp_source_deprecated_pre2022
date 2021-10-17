// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro/Save/SavePro.h"
#include "App/Reg.h"
#include "App/Scope.h"

#include "Ui/Save/SaveUi.h"


USavePro* USavePro::Create()
{
	USavePro* Neu = NewObject<USavePro>();
	return Neu;
}