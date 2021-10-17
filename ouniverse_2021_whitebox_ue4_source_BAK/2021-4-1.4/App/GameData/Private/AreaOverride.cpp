// Fill out your copyright notice in the Description page of Project Settings.


#include "AreaOverride.h"

void UAreaOverride::SetAreaOverride(UArea* Area, FAddress Address)
{
	Area_ = Area;
	Address_ = Address;
}

bool UAreaOverride::IsActive()
{
	if (Area_ != NULL)
	{
		return true;
	}
	return false;

}