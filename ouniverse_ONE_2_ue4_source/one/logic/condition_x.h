// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "condition_x.h"
#include "../type/json.h"

class Condition_X
{


public:

	Condition_X() {};

	static Condition_X* Factory(int ConditionID);

	virtual bool FromJson(JsonS* J);
	virtual JsonS ToJson();

	bool Solve();

};