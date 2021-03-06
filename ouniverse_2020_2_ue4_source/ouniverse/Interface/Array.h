//Copyright 2015-2019, All Rights Reserved.

/**

## Array

**Class:** ArrayC

Generic array implementation.
> Wrapper around a std::vector

*/

#pragma once

#include <vector>

#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"

template <typename T>
class ArrayC
{

public:

	void Init(int Amount, T Default)
	{		
		Vector_.assign(Amount, Default);
	}

	void Add(T NewT)
	{
		Vector_.push_back(NewT);
	}

	T& At(int Index)
	{
		return Vector_[Index];
	}

	void Insert(int Index, T NewT)
	{
		Vector_.insert(Vector_.begin()+Index,NewT);
	}

	void Erase(int Index)
	{
		Vector_.erase(Vector_.begin() + Index);
	}
	
	bool EraseElement(T InT)
	{
		int Ix = Find(InT);
		if (Ix != -1)
		{
			Erase(Ix);
			return true;
		}

		return false;
	}

	T& operator[] (int Index)
	{
		return Vector_[Index];
	}

	void operator+=(T NewT)
	{
		return Vector_.push_back(NewT);
	}

	int Len()
	{
		return Vector_.size();
	}


	int Find(T InT)
	{
		int l = Len();
		for (int i = 0; i < l; i++)
		{
			if (Vector_[i] == InT)
			{
				return i;
			}
		}

		return -1;
	}


	std::vector <T> Vector()
	{
		return Vector_;
	}

	std::vector <T> Vector_;

	void Append(ArrayC <T> InArr)
	{
		std::vector <T> New;
		New.reserve(Vector_.size() + InArr.Vector_.size()); // preallocate memory
		New.insert(New.end(), Vector_.begin(), Vector_.end());
		New.insert(New.end(), InArr.Vector_.begin(), InArr.Vector_.end());

		Vector_ = New;
	}

	void Cull()
	{
		int l = Len();
		for (int i = 0; i < l; i++)
		{
			delete Vector_[0];
		}

		Vector_.clear();
	}

	void Clear()
	{
		Vector_.clear();
	}
};