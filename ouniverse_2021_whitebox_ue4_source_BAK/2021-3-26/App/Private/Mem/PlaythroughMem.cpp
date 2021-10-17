// Fill out your copyright notice in the Description page of Project Settings.


#include "Mem/PlaythroughMem.h"


FPlaythroughMem::FPlaythroughMem()
{

}

FStoryMem* FPlaythroughMem::AddStoryMem(int Key)
{
	return &Stories.Add(Key, FStoryMem());
}

FStoryMem* FPlaythroughMem::GetStoryMem(int Key)
{
	return Stories.Find(Key);
}

FCompanionMem* FPlaythroughMem::AddCompanionMem(int Key)
{
	return &Companions.Add(Key, FCompanionMem());
}

FCompanionMem* FPlaythroughMem::GetCompanionMem(int Key)
{
	return Companions.Find(Key);
}