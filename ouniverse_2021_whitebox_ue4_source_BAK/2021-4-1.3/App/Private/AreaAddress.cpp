// Fill out your copyright notice in the Description page of Project Settings.


#include "AreaAddress.h"


bool FAreaAddress::IsValid()
{
	if (Area != NULL)
	{
		return true;
	}

	return false;
}

void FAreaAddress::Invalidate()
{
	Area = NULL;
}

void UAreaAddressUtil::MakeAreaAddress(UArea* Area, FAddress Address, FAreaAddress& AreaAddress)
{
	FAreaAddress AA = FAreaAddress(Area,Address);
	AreaAddress = AA;
}