// Fill out your copyright notice in the Description page of Project Settings.


#include "Mem/Mem.h"


FMemState::FMemState()
{

}

void FMemState::Restart()
{
	*this = FMemState();
}

FStoryMem* FMemState::AddStoryMem(int Key)
{
	return &Stories.Add(Key, FStoryMem());
}

FStoryMem* FMemState::GetStoryMem(int Key)
{
	return Stories.Find(Key);
}

FCompanionMem* FMemState::AddCompanionMem(int Key)
{
	return &Companions.Add(Key, FCompanionMem());
}

FCompanionMem* FMemState::GetCompanionMem(int Key)
{
	return Companions.Find(Key);
}