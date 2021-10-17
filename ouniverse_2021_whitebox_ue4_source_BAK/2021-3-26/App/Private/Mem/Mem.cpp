// Fill out your copyright notice in the Description page of Project Settings.


#include "Mem/Mem.h"


FMemState::FMemState()
{

}

void FMemState::Restart()
{
	*this = FMemState();
}