//Copyright 2015-2019, All Rights Reserved.

/**

## Json

**Struct:**  JsonS

Json read-only interface which is a wrapper around rapidjson

*/

#pragma once

#include "../external/nlohmann/json.hpp"

#include "array.h"

using json = nlohmann::json;


struct JsonS
{
	json J;

	JsonS() {};
	JsonS(int InInt);
	JsonS(JsonS* InJ);
	JsonS(json InJ);
	JsonS(FString InJ);
	JsonS(const char* InJ);
	JsonS(ArrayC<JsonS> InArr);

	bool Parse(FString JSerialized);

	static bool IsValidJson(FString JSerialized);

	FString Serialize();
	FString Serialize(const int Indent, const char IndentChar, const bool Asci, const json::error_handler_t ErrorHandler);

	int Num();

	JsonS operator[](const char* Query);
	JsonS operator[](int Query);

	TArray<FString> GetKeys();
	
	JsonS At(int Query);
	JsonS Key(const char* Query);


	void Array(ArrayC<JsonS> InArr);

	bool Has(const char* InKey);
	bool Try(JsonS& Output, const char* InKey);

	bool IsNumber();
	bool IsString();
	bool IsArray();

	bool IsNumber(const char* Key);
	bool IsString(const char* Key);
	bool IsArray(const char* Key);

	int Int(const char* Query);
	int Int();

	bool TryInt(int& Output, const char* Query);
	bool TryInt(int& Output);

	operator JsonS* ()
	{
		return this;
	}

	FString String(const char* Query);
	FString String();

	bool TryString(FString& Output,const char* Query);
	bool TryString(FString& Output);

	float Float(const char* Query);
	float Float();

	bool TryFloat(float& Output, const char* Query);
	bool TryFloat(float& output);

	bool TryArray(JsonS& Output, const char* Query);
	bool TryArray(JsonS& Output);

	json::value_t Type();

	void Add(const char* Key, int Val);

	void Add(const char* Key, FString Val);

	void Add(const char* Key, std::vector<nlohmann::json> Val);

	void Add(const char* Key, JsonS Val);

	void Add(const char* Key, ArrayC<JsonS> Val);

	void Erase(const char* Key);

};