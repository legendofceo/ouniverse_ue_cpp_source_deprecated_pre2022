// Fill out your copyright notice in the Description page of Project Settings.

#include "ModeUE.h"
#include "HudUE.h"
#include "ControlUE.h"

AModeUE::AModeUE()
{
	//PlayerControllerClass = 
	HUDClass = AHudUE::StaticClass();
	PlayerControllerClass = AControlUE::StaticClass();
}
