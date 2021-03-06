//Copyright 2015-2019, All Rights Reserved.

#include "Interface/String.h"
#include <sstream>
#include <algorithm>
#include <cctype>


StringC::StringC()
{
	s = "";
};


StringC::StringC(const char* inText)
{
	s = std::string(inText);
};


StringC::StringC(std::string inText)
{
	s = inText;
};


StringC::StringC(FString Text)
{
	s = TCHAR_TO_UTF8(*Text);

};

StringC::StringC(FText Text)
{
	s = TCHAR_TO_UTF8(*(Text.ToString()));
};

StringC::StringC(bool In)
{
	if(In)
	{
		s = "1";
		return;
	}
		s = "0";
}


StringC::StringC(float In)
{
	s =  std::to_string(In);
}


StringC::StringC(int In)
{
	s = std::to_string(In);
}

const char* StringC::ToChar()
{
	return s.c_str();
};

const char* StringC::ToChar() const
{
	return s.c_str();
};

const char* StringC::ToPath()
{
	FString Path = ToFString();
	return StringC(Path).ToChar();
};


std::string StringC::ToStd()
{
	return s;
};


std::string StringC::ToStd() const
{
	return s;
};


FString StringC::ToFString()
{
	return UTF8_TO_TCHAR(s.c_str());
};

FText StringC::ToFText()
{
	return FText::FromString(ToFString());
};

bool StringC::operator<(const StringC& l) const
{
	return s < l.ToStd();
}


bool StringC::operator==(StringC In)
{
	if (s == In.ToStd())
	{
		return true;
	}
	return false;
}


bool StringC::operator!=(StringC In)
{
	if (s == In.ToStd())
	{
		return false;
	}
	return true;
}


StringC StringC::operator+(StringC In)
{
	return StringC(s + In.ToStd());
}


StringC StringC::operator+(int In)
{
	return StringC(s + std::to_string(In));
}

StringC StringC::operator+(std::string In)
{
	return StringC(s + In);
}


StringC StringC::operator+(const char* In)
{
	return StringC(s += In);
}

StringC& StringC::operator+=(StringC In)
{
	s += In.ToStd();
	return *this;
}


StringC& StringC::operator+=(int In)
{
	s += std::to_string(In);
	return *this;
}

StringC& StringC::operator+=(std::string In)
{
	s += In;
	return *this;
}


StringC& StringC::operator+=(const char* In)
{
	s += In;
	return *this;
}


StringC StringC::operator[](int Index)
{
	return StringC(std::string(1, s.at(Index)));
}


StringC StringC::operator/(const char* In)
{
	StringC New = StringC(s);
	New += "/";
	New += In;
	return New;
}


StringC StringC::operator/(StringC In)
{
	StringC New = StringC(s);
	New += "/";
	New += In;
	return New;
}

StringC StringC::operator&(StringC In)
{
	StringC New = StringC(s);
	New += " ";
	New += In;
	return New;
}


StringC StringC::NL()
{
	return StringC(s + "\n");
}


bool StringC::BeBool(bool& Out)
{
	if (s == "0")
	{
		Out = false;
		return true;
	}
	else if (s == "1")
	{
		Out = true;
		return true;
	}

	return false;
}


bool StringC::BeFullBool(bool& Out)
{
	if (s == "0" || s == "false")
	{
		Out = false;
		return true;
	}
	else if (s == "1" || s == "true")
	{
		Out = true;
		return true;
	}

	return false;
}


bool StringC::BeFloat(float& Out)
{
	auto i = std::istringstream(s);

	i >> Out;
	i >> std::ws;

	return !i.fail() && i.eof();
}


bool StringC::BeInt(int& Out)
{
	std::istringstream i(s);
	//char c;
	if (!(i >> Out))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool StringC::BeInt(long long& Out)
{
	std::istringstream i(s);
	//char c;
	if (!(i >> Out))
	{
		return false;
	}
	else
	{
		return true;
	}
}


int StringC::Len()
{
	return s.length();
}


StringC& StringC::Sanitize()
{
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
		}).base(), s.end());

	return *this;
}


StringC& StringC::NewLine()
{
	s = s + "\n";
	return *this;
}


StringC StringC::RemoveLastChar()
{

	StringC Temp = StringC(s);
	Temp.ToStd().pop_back();

	return Temp;
}


StringC StringC::SubString(int Index1, int Index2)
{
	//Might need to be s = s.pop_back() idk
	return s.substr(Index1, Index2);
}

ArrayC<StringC> StringC::Split(char Delim)
{
	ArrayC<StringC> Splits;
	std::string split;
	std::istringstream ss(StringC(s).ToStd());
	while (std::getline(ss, split, Delim))
	{
		Splits.Add(StringC(split));
	}

	return Splits;
}

StringC StringC::FindAndReplace(const char* InFind, StringC InReplace)
{
	
	std::string Neu = std::string(s);
	std::string FindString = InFind;
	size_t pos = Neu.find(FindString);
	if (pos != std::string::npos)
	{
		Neu.replace(pos, FindString.size(), InReplace.ToStd());
	}
	return Neu;
}

StringC& StringC::FindAndReplaceMe(const char* InFind, StringC InReplace)
{
	std::string FindString = InFind;
	size_t pos = s.find(FindString);
	if (pos != std::string::npos)
	{
		s.replace(pos, FindString.size(), InReplace.ToStd());
	}

	return *this;
}


StringC StringC::FindAndReplaceAll(const char* InFind, StringC InReplace)
{
	std::string FindString = InFind;
	std::string Neu = std::string(s);
	size_t pos = Neu.find(FindString);
	while (pos != std::string::npos)
	{
		Neu.replace(pos, FindString.size(), InReplace.ToStd());
		pos = Neu.find(FindString, pos + InReplace.ToStd().size());
	}

	return Neu;
}

StringC& StringC::FindAndReplaceAllMe(const char* InFind, StringC InReplace)
{
	std::string FindString = InFind;
	size_t pos = s.find(FindString);
	while (pos != std::string::npos)
	{
		s.replace(pos, FindString.size(), InReplace.ToStd());
		pos = s.find(FindString, pos + InReplace.ToStd().size());
	}

	return *this;
}


StringC StringC::TrimExtension()
{
	StringC NewString(s);
	return NewString.s.erase(s.find_last_of("."), NPOS());
}


StringC StringC::Trim(int From)
{
	return StringC(s.erase(From, NPOS()));
}


StringC StringC::Trim(int From, int To)
{
	return StringC(s.erase(From, To));
}


int StringC::FindLast(const char* S)
{
	return s.find_last_of(S);
}


ArrayC<StringC> StringC::Delimit(StringC S, char D)
{
	std::stringstream ss(S.ToStd());
	ArrayC<StringC> Result;

	while (ss.good())
	{
		std::string substr;
		std::getline(ss, substr, D);
		Result.Add(substr);
	}

	return Result;
}

int StringC::ToIntZeroFail()
{
	int Number = 0;

	if (!BeInt(Number))
	{
		Number = 0;
	}

	return Number;
}

StringC StringC::ToUpper()
{
	std::string ns = std::string(s);
	std::transform(ns.begin(), ns.end(), ns.begin(), ::toupper);
	return StringC(ns);
}

StringC StringC::ToLower()
{
	std::string ns = std::string(s);
	std::transform(ns.begin(), ns.end(), ns.begin(), ::tolower);
	return StringC(ns);
}


bool StringC::Contains(const char* InChar)
{
	if (s.find(InChar) != NPOS())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool StringC::Contains(StringC InString)
{
	return Contains(InString.ToChar());
}

bool StringC::ContainsOnly(StringC InS)
{
	if (s.find_first_not_of(InS.ToStd()) != std::string::npos)
	{
		return false;
	}

	return true;

}

int StringC::NPOS()
{
	return -1;
}