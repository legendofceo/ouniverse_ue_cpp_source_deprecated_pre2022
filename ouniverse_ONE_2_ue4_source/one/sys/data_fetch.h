// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "data_address.h"

class Form_F;


struct AtlasFetchS
{

private:

	bool bSuccess = false;

public:

	UAtlas* Atlas_;

	AtlasFetchS() {};

	AtlasFetchS(int InPackUN);

	bool Success();

	UAtlas* Atlas();
};

struct FetchDataS
{

public:

	Form_F* Form;
	bool bSuccess = false;
	AtlasFetchS AtlasFetch;	

	FetchDataS() {};

	FetchDataS(FDataAddress InAddress);

	bool Success()
	{
		return bSuccess;
	}
};