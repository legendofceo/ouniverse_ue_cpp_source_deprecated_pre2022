//Copyright 2015-2019, All Rights Reserved.


#pragma once

class UWorld;
class UObject;

class ScopeC
{

public:

	static void Initialize(UObject* InWorldContextObject, UWorld* InWorld);

public:

	static UWorld* World();
	static UObject* WorldContext();
};