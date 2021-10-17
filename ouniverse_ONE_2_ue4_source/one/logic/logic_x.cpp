// Fill out your copyright notice in the Description page of Project Settings.

#include "logic_x.h"
#include "condition_x.h"
#include "../type/json.h"




Logic_X* Logic_X::Factory(int LogicID)
{
	return new Logic_X();
}

Logic_X* Logic_X::FactoryFromJson(JsonS* J)
{

	Logic_X* N = Logic_X::Factory(J->Int("%"));
	N->FromJson(J);
	return N;
}




bool IfLogic_X::Trigger()
{


	return false;
}



IfResultS IfStatement_X::Solve()
{
	IfResultS Result;
	int L = OrList.Len();

	for (int i = 0; i < L; i++)
	{
		if (DoAnds(&OrList[i]) == true)
		{
			bool Handled = DoThens();

			if (Handled)
			{
				Result.Handled();
			}
			Result.Qualify();
			return Result;
		}
	}

	return Result;
}

bool IfStatement_X::DoAnds(ArrayC<Condition_X*>* Ands)
{
	int L = Ands->Len();
	for (int i = 0; i < L; i++)
	{
		bool AllSuccess = true;
		if (!Ands->At(i)->Solve() == false)
		{
			AllSuccess = false;
		}

		if (AllSuccess)
		{
			return true;
		}
	}

	return false;
}

bool IfStatement_X::DoThens()
{
	int L = Thens.Len();
	for (int i = 0; i < L; i++)
	{
		bool AllSuccess = true;
		if (!Thens[i]->Trigger() == false)
		{
			AllSuccess = false;
		}

		if (AllSuccess)
		{
			return true;
		}
	}

	return false;
}
