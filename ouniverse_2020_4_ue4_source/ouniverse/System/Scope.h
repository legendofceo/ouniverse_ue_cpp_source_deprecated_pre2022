// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

class UWorld;
class UObject;

class BootC;

class ScopeC
{
	friend BootC;

private:

	ScopeC(UObject* InWorldContextObject, UWorld* InWorld);

public:

	static UWorld* World();
	static UObject* WorldContext();
};