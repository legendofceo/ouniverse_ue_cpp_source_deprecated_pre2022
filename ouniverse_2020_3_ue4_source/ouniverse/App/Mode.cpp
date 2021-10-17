// Fill out your copyright notice in the Description page of Project Settings.


#include "App/Mode.h"
#include "App/Control.h"

AMode::AMode()
{
	PlayerControllerClass = AControl::StaticClass();
}