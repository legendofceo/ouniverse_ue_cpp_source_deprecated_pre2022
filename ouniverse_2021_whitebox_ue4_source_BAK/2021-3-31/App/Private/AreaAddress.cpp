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

void UAreaAddressUtil::MakeAreaAddress(TSoftClassPtr<UArea> Area, FName Address, FAreaAddress& AreaAddress)
{
	FAreaAddress AA = FAreaAddress();
	AA.Area = Area;
	AA.Address = Address;
	AreaAddress = AA;
}