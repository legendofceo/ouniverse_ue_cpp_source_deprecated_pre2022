// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interface/Map.h"
#include "Interface/String.h"

class DataD;
class DataLibC;

class DataPackC
{
	friend DataLibC;

public:

	DataPackC(const char* InPath);

	int U();
	StringC I();

private:

	int U_;
	StringC I_;

	MapC<int, DataD*> Lib_;
};