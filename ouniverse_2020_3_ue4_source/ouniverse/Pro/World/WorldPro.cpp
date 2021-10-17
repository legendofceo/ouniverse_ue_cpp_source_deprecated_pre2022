// Fill out your copyright notice in the Description page of Project Settings.


#include "Pro/World/WorldPro.h"


UWorldPro* UWorldPro::Create()
{
	UWorldPro* Neu = NewObject<UWorldPro>();
	return Neu;
}