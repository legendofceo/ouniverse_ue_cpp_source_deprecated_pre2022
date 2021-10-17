// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interface/String.h"

struct JsonS;

class DataD
{

public:

	void Load(JsonS* J);

	int U();
	StringC I();

private:

	int U_;
	StringC I_;
	
};
