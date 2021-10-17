// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager.h"


UManager::UManager()
{

}

void UManager::InitComplete()
{
	bInit = true;
	OnInitComplete.Broadcast(this);
}