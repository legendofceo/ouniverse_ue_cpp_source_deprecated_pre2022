//Copyright 2015-2019, All Rights Reserved.

/**

## String

**Class:** StringC

Generic string implementation.
> Wrapper around a std::string with some custom functionality.

*/

#pragma once

#include "CoreMinimal.h"
#include "Interface/Array.h"


#include <string>

class StringC
{

public:

	StringC();

	StringC(const char* inText);
	
	StringC(std::string inText);

	StringC(FString Text);

	StringC(FText Text);

	StringC(float In);
	
	StringC(int In);


	StringC(bool In);

	const char* ToChar();

	const char* ToChar() const;

	const char* ToPath();

	std::string ToStd();

	std::string ToStd() const;

	FString ToFString();
	FText ToFText();

	bool operator<(const StringC& l) const;

	bool operator!=(StringC In);

	bool operator==(StringC In);

	StringC operator+(StringC In);

	StringC operator+(int In);
	
	StringC operator+(std::string In);

	StringC operator+(const char* In);

	StringC& operator+=(StringC In);

	StringC& operator+=(int In);

	StringC& operator+=(std::string In);

	StringC& operator+=(const char* In);
	
	StringC operator/(const char* In);

	StringC operator/(StringC In);

	StringC operator&(StringC In);

	StringC operator[](int Index);
	
	StringC NL();
	//operator const char* ()  { return ToChar();};



	bool BeBool(bool& Out);

	bool BeFullBool(bool& Out);

	bool BeFloat(float& Out);

	bool BeInt(int& Out);

	bool BeInt(long long& Out);

	int Len();

	StringC& Sanitize();

	StringC& NewLine();

	StringC RemoveLastChar();

	StringC SubString(int Index1, int Index2);

	ArrayC<StringC> Split(char Delim);
	
	StringC FindAndReplace(const char* InFind, StringC InReplace);

	StringC& FindAndReplaceMe(const char* InFind, StringC InReplace);
	
	StringC FindAndReplaceAll(const char* InFind, StringC InReplace);

	StringC& FindAndReplaceAllMe(const char* InFind, StringC InReplace);

	StringC Trim(int From);

	StringC Trim(int From, int To);

	StringC TrimExtension();

	int FindLast(const char* S);

	static int NPOS();

	ArrayC<StringC> Delimit(StringC S, char D);

	int ToIntZeroFail();


	StringC ToUpper();

	StringC ToLower();

	bool Contains(const char* InChar);
	bool Contains(StringC InString);

	bool ContainsOnly(StringC InS);

private:

	std::string s;

public:

	FORCEINLINE static std::string FStringToString(FString Text) { return TCHAR_TO_UTF8(*Text); };

	FORCEINLINE static const char* FStringToChar(FString Text) { return TCHAR_TO_UTF8(*Text); };

	FORCEINLINE static FString StringToFString(std::string Text) { return UTF8_TO_TCHAR(Text.c_str()); };

	FORCEINLINE static const char* StringToChar(std::string Text) { return Text.c_str(); };

};

