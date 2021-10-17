// Fill out your copyright notice in the Description page of Project Settings.



#include "Data.h"


USave::USave()
{

}

UData* UData::Create()
{
	UData* Obj = NewObject<UData>();
	return Obj;
}

UData::UData()
{

}