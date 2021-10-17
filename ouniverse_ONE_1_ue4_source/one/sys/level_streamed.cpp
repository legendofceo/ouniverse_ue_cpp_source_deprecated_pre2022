// Fill out your copyright notice in the Description page of Project Settings.


#include "level_streamed.h"


//bool ALevelBase::ReactToHighNoon_Implementation() {
	// Default behaviour for how a frog would react at noon //GoSwim(); //...
//	return true;
//}



void ALevelStreamed::Command(FName Command, FName Relay)
{
	OnCommand(Command,Relay);
}