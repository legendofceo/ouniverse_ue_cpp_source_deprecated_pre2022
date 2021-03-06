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

StringC JsonS::Serialize(const int Indent, const char IndentChar, const bool Asci, const json::error_handler_t ErrorHandler)
{
	return StringC(J.dump(Indent,IndentChar,Asci,ErrorHandler));
}

ArrayC<StringC> JsonS::GetKeys()
{
	ArrayC<StringC> Arr;

	for (const auto& item : J.items())
	{
		Arr.Add(item.key());
	}

	return Arr;
}

int JsonS::Len()
{
	return J.size();
}

json::value_t JsonS::Type()
{
	return J.type();
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



void JsonS::Erase(const char* Key)
{
	J.erase(Key);
}