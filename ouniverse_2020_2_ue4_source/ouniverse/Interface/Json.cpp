//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Json.h"
#include <vector>

JsonS::JsonS(json InJ)
{
	J = InJ;
}


JsonS::JsonS(const char* JSerialized)
{
	J = json::parse(JSerialized);
}

JsonS::JsonS(int InInt)
{
	J = InInt;
}

JsonS::JsonS(FormUID InUID)
{
	J = InUID.ForJson();
}

JsonS::JsonS(AtlasUID InUID)
{
	J = InUID.ForJson();
}

JsonS::JsonS(StringC JSerialized)
{
	J = json::parse(JSerialized.ToChar());
}

JsonS JsonS::Key(const char* Query)
{
	return JsonS(J[Query]);
}

JsonS JsonS::operator[](const char* Query)
{
	return Key(Query);
}

JsonS JsonS::operator[](int Query)
{
	return JsonS(J[Query]);
}

JsonS JsonS::At(int Query)
{
	return JsonS(J[Query]);
}

StringC JsonS::Serialize()
{
	return StringC(J.dump());
}
int JsonS::Len()
{
	return J.size();
}

void JsonS::Array(ArrayC<JsonS> InArr)
{
	std::vector<nlohmann::json> JArr;

	for(int i=0;i<InArr.Len();i++)
	{
		JArr.push_back(InArr[i].J);
	}
	
	JsonS Temp = JsonS();
	Temp.Add("temp", JArr);

	J = JsonS(Temp.Key("temp")).J;
	
}

bool JsonS::Has(const char* InKey)
{
	return J.contains(InKey);
}

bool JsonS::IsNumber()
{
	return J.is_number();

}

bool JsonS::IsString()
{
	return J.is_string();
}

StringC JsonS::String(const char* Query)
{
	return J[Query].get<std::string>();
}

StringC JsonS::String()
{
	return J.get<std::string>();
}

int JsonS::Int(const char* Query)
{
	return J[Query].get<int>();
}

int JsonS::Int()
{
	return J.get<int>();
}

float JsonS::Float(const char* Query)
{
	return J[Query].get<float>();
}

float JsonS::Float()
{
	return J.get<float>();
}


void JsonS::Add(const char* Key, int Val)
{
	J.emplace(Key, Val);
}

void JsonS::Add(const char* Key, StringC Val)
{
	J.emplace(Key, Val.ToChar());
}

void JsonS::Add(const char* Key, std::vector<nlohmann::json> Val)
{
	J.emplace(Key, Val);
}

void JsonS::Add(const char* Key, JsonS Val)
{
	J.emplace(Key, Val.J);
}

void JsonS::Add(const char* Key, ArrayC<JsonS> Val)
{
	JsonS NewJ = JsonS();
	NewJ.Array(Val);
	J.emplace(Key, NewJ.J);
}


void JsonS::Add(const char* Key, FormUID Val)
{
	J.emplace(Key, Val.ForJson());
}

void JsonS::Add(const char* Key, AtlasUID Val)
{
	J.emplace(Key, Val.ForJson());
}

U8 JsonS::UInt8()
{
	return U8(J.get<int>());
}

U16 JsonS::UInt16()
{
	return U16(J.get<int>());
}

U32 JsonS::UInt32()
{
	return U32(J.get<int>());
}

U64 JsonS::UInt64()
{
	return U64(J.get<int>());
}


U8 JsonS::UInt8(const char* Query)
{
	return U8(J[Query].get<int>());
}

U16 JsonS::UInt16(const char* Query)
{
	return U16(J[Query].get<int>());
}

U32 JsonS::UInt32(const char* Query)
{
	return U32(J[Query].get<int>());
}

U64 JsonS::UInt64(const char* Query)
{
	return U64(J[Query].get<int>());
}




AtlasUID JsonS::ToAtlasUID()
{
	return AtlasUID(J.get<int>());
}

AtlasUID JsonS::ToAtlasUID(const char* Query)
{
	return AtlasUID(J[Query].get<int>());
}

FormUID JsonS::ToFormUID()
{
	return FormUID(J.get<int>());
}

FormUID JsonS::ToFormUID(const char* Query)
{
	return FormUID(J[Query].get<int>());
}

LoadoutUID JsonS::ToLoadoutUID()
{
	return LoadoutUID(J.get<int>());
}

LoadoutUID JsonS::ToLoadoutUID(const char* Query)
{
	return LoadoutUID(J[Query].get<int>());
}