//Copyright 2015-2019, All Rights Reserved.

/**

## Json

**Struct:**  JsonS

Json read-only interface which is a wrapper around rapidjson

*/

#pragma once

#include "nlohmann/json.hpp"

#include "Interface/String.h"
#include "Interface/Int.h"

#include "System/FormUID.h"
#include "System/AtlasUID.h"

#include "System/LoadoutUID.h"

using json = nlohmann::json;


struct JsonS
{
	json J;

	JsonS() {};
	JsonS(const char* JSerialized);
	JsonS(int InInt);
	JsonS(AtlasUID InUID);
	JsonS(FormUID InUID);

	JsonS(StringC JSerialized);

	JsonS(json InJ);

	StringC Serialize();

	int Len();

	void Array(ArrayC<JsonS> InArr);

	bool Has(const char* InKey);

	bool IsNumber();
	bool IsString();

	int Int(const char* Query);
	int Int();

	StringC String(const char* Query);
	StringC String();

	float Float(const char* Query);
	float Float();

	JsonS operator[](const char* Query);
	JsonS operator[](int Query);

	

	JsonS At(int Query);
	
	JsonS Key(const char* Query);

	void Add(const char* Key, int Val);

	void Add(const char* Key, StringC Val);

	void Add(const char* Key, std::vector<nlohmann::json> Val);

	void Add(const char* Key, JsonS Val);

	void Add(const char* Key, ArrayC<JsonS> Val);

	void Add(const char* Key, FormUID Val);

	void Add(const char* Key, AtlasUID Val);

	U8  UInt8();
	U16 UInt16();
	U32 UInt32();
	U64 UInt64();

	U8  UInt8(const char* Query);
	U16 UInt16(const char* Query);
	U32 UInt32(const char* Query);
	U64 UInt64(const char* Query);

	AtlasUID ToAtlasUID();
	AtlasUID ToAtlasUID(const char* Query);

	FormUID ToFormUID();
	FormUID ToFormUID(const char* Query);

	LoadoutUID ToLoadoutUID();
	LoadoutUID ToLoadoutUID(const char* Query);

};

