//Copyright 2015-2019, All Rights Reserved.

/**

## Json

**Struct:**  JsonS

Json read-only interface which is a wrapper around rapidjson

*/

#pragma once

#include "nlohmann/json.hpp"

#include "Interface/String.h"

using json = nlohmann::json;


struct JsonS
{
	json J;

	JsonS() {};
	JsonS(const char* JSerialized);
	JsonS(int InInt);

	JsonS(StringC JSerialized);

	JsonS(json InJ);

	StringC Serialize();
	StringC Serialize(const int Indent, const char IndentChar, const bool Asci, const json::error_handler_t ErrorHandler);

	int Len();

	void Array(ArrayC<JsonS> InArr);

	bool Has(const char* InKey);

	bool IsNumber();
	bool IsString();

	int Int(const char* Query);
	int Int();

	ArrayC<StringC> GetKeys();

	StringC String(const char* Query);
	StringC String();

	float Float(const char* Query);
	float Float();

	JsonS operator[](const char* Query);
	JsonS operator[](int Query);

	
	json::value_t Type();

	JsonS At(int Query);
	
	JsonS Key(const char* Query);

	void Add(const char* Key, int Val);

	void Add(const char* Key, StringC Val);

	void Add(const char* Key, std::vector<nlohmann::json> Val);

	void Add(const char* Key, JsonS Val);

	void Add(const char* Key, ArrayC<JsonS> Val);

	void Erase(const char* Key);


	

};

