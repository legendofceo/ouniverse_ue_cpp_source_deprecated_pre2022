//Copyright 2015-2019, All Rights Reserved.

#include "Type/Json.h"
#include <vector>




JsonS::JsonS(json InJ)
{
	J = InJ;
}


JsonS::JsonS(int InInt)
{
	J = InInt;
}

JsonS::JsonS(JsonS* InJ)
{
	J = InJ->J;
}

JsonS::JsonS(FString InJ)
{
	J = TCHAR_TO_UTF8(*InJ);
}


JsonS::JsonS(const char* InJ)
{
	J = InJ;
}

JsonS::JsonS(ArrayC<JsonS> InArr)
{
	Array(InArr);
}

bool JsonS::IsValidJson(FString JSerialized)
{
	return json::accept(TCHAR_TO_UTF8(*JSerialized));
}

bool JsonS::Parse(FString JSerialized)
{
	if (IsValidJson(JSerialized))
	{
		J = json::parse(TCHAR_TO_UTF8(*JSerialized));
		return true;
	}

	return false;
}

FString JsonS::Serialize()
{
	return UTF8_TO_TCHAR(J.dump().c_str());
}

FString JsonS::Serialize(const int Indent, const char IndentChar, const bool Asci, const json::error_handler_t ErrorHandler)
{
	return UTF8_TO_TCHAR(J.dump(Indent, IndentChar, Asci, ErrorHandler).c_str());
}

JsonS JsonS::operator[](const char* Query)
{
	return Key(Query);
}

JsonS JsonS::operator[](int Query)
{
	return JsonS(J[Query]);
}


TArray<FString> JsonS::GetKeys()
{
	TArray<FString> Arr;

	for (const auto& item : J.items())
	{
		Arr.Add(item.key().c_str());
	}

	return Arr;
}

JsonS JsonS::At(int Query)
{
	return JsonS(J[Query]);
}

JsonS JsonS::Key(const char* Query)
{
	return JsonS(J[Query]);
}

int JsonS::Num()
{
	return J.size();
}


void JsonS::Array(ArrayC<JsonS> InArr)
{
	std::vector<nlohmann::json> JArr;

	for (int i = 0; i < InArr.Len(); i++)
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

bool JsonS::Try(JsonS& Output,const char* InKey)
{
	if (Has(InKey))
	{
		Output = Key(InKey);
		return true;
	}
	return false;
}

bool JsonS::IsString()
{
	return J.is_string();
}

bool JsonS::IsNumber()
{
	return J.is_number();
}

bool JsonS::IsArray()
{
	return J.is_array();
}

bool JsonS::IsString(const char* Key)
{
	return J[Key].is_string();
}

bool JsonS::IsNumber(const char* Key)
{
	return J[Key].is_number();
}

bool JsonS::IsArray(const char* Key)
{
	return J[Key].is_array();
}




FString JsonS::String(const char* Query)
{
	return  UTF8_TO_TCHAR(J[Query].get<std::string>().c_str());
}

FString JsonS::String()
{
	return UTF8_TO_TCHAR(J.get<std::string>().c_str());
}

bool JsonS::TryString(FString& Output, const char* Query)
{
	if (Has(Query))
	{
		if (Key(Query).TryString(Output))
		{
			return true;
		}
	}
	return false;
}

bool JsonS::TryString(FString& Output)
{
	if (IsString())
	{
		Output = String();
		return true;
	}
	return false;
}



int JsonS::Int(const char* Query)
{
	return J[Query].get<int>();
}

int JsonS::Int()
{
	return J.get<int>();
}

bool JsonS::TryInt(int& Output, const char* Query)
{
	if (Has(Query))
	{
		if (Key(Query).TryInt(Output))
		{
			return true;
		}
	}
	return false;
}

bool JsonS::TryInt(int& Output)
{
	if (IsNumber())
	{
		Output = Int();
		return true;
	}
	return false;
}



float JsonS::Float(const char* Query)
{
	return J[Query].get<float>();
}

float JsonS::Float()
{
	return J.get<float>();
}

bool JsonS::TryFloat(float& Output, const char* Query)
{
	if (Has(Query))
	{
		if (Key(Query).TryFloat(Output))
		{
			return true;
		}
	}
	return false;
}

bool JsonS::TryFloat(float& Output)
{
	if (IsNumber())
	{
		Output = Float();
		return true;
	}
	return false;
}


bool JsonS::TryArray(JsonS& Output, const char* Query)
{
	if (Has(Query))
	{
		if (Key(Query).TryArray(Output))
		{
			return true;
		}
	}
	return false;
}

bool JsonS::TryArray(JsonS& Output)
{
	if (IsArray())
	{
		Output = this;
		return true;
	}
	return false;
}

void JsonS::Add(const char* Key, int Val)
{
	J.emplace(Key, Val);
}

void JsonS::Add(const char* Key, FString Val)
{
	J.emplace(Key, TCHAR_TO_UTF8(*Val));
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

json::value_t JsonS::Type()
{
	return J.type();
}