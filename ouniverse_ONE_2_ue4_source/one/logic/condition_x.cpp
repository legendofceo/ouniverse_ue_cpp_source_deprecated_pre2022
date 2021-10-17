// Fill out your copyright notice in the Description page of Project Settings.

#include "condition_x.h"



bool Condition_X::Solve()
{
	return true;
}

Condition_X* Condition_X::Factory(int ConditionID)
{
	return new Condition_X();
}

bool Condition_X::FromJson(JsonS* J)
{
	return true;
}

JsonS Condition_X::ToJson()
{
	return JsonS();
}