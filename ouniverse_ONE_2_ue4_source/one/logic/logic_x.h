// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "logic_x.h"
#include "../type/array.h"
#include "../type/json.h"

class Condition_X;


struct IfResultS
{

	bool Handled_ = false;
	bool Qualified_ = false;

	bool Handled()
	{
		return Handled_;
	}

	bool Qualified()
	{
		return Qualified_;
	}

	void Qualify()
	{
		Qualified_ = true;
	}

};


class Logic_X
{


public:

	Logic_X() {};
	virtual ~Logic_X() {};
	static Logic_X* Factory(int LogicID);
	static Logic_X* FactoryFromJson(JsonS* J);
	virtual bool FromJson(JsonS* J) { return false; };
	virtual JsonS ToJson() { return JsonS(); };
	virtual bool Trigger() { return false; };
};


class IfStatement_X
{

public:

	IfStatement_X() {};
	ArrayC<ArrayC<Condition_X*>> OrList;

	IfResultS Solve();

	ArrayC<Logic_X*> Thens;

	bool DoAnds(ArrayC<Condition_X*>* Ands);
	bool DoThens();
};



class IfLogic_X : public Logic_X
{


public:

	IfLogic_X() {};

	virtual bool Trigger() override;
	ArrayC<IfStatement_X*> Ifs;

};