// Fill out your copyright notice in the Description page of Project Settings.


#include "LogPP.h"


FLogEntryPP& FLogEntryPP::W(FString InText)
{
	Text = InText;
	return *this;
}

FLogEntryPP& FLogEntryPP::S(FName InSystem)
{
	System = InSystem;
	return *this;
}


FLogEntryPP& FLogEntryPP::I(FName InID)
{
	ID = InID;
	return *this;
}

FLogEntryPP& FLogEntryPP::T(LogTypePP InLogType)
{
	LogType = InLogType;
	return *this;
}

FLogEntryPP& FLogEntryPP::DebugM()
{
	return DebugM(FColor::Magenta);
}

FLogEntryPP& FLogEntryPP::DebugM(FColor Color)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, Color, *OutputS());
	return *this;
}

FString FLogEntryPP::OutputS()
{
	FString Output = "";

	Output += System.ToString();

	if (!ID.IsNone())
	{
		Output += (" #" + ID.ToString());
	}

	Output += " | ";

	Output += Text;
	return Output;
}

FLogEntryPP& FLogPP::New()
{
	FLogEntryPP NewEntry = FLogEntryPP();
	NewEntry.Time = FPlatformTime::Seconds();
	return Entries.Add_GetRef(NewEntry);
}

FString FLogPP::OutputS()
{
	FString Output;
	for (FLogEntryPP LE : Entries)
	{
		Output += LE.OutputS();
		Output += LINE_TERMINATOR;
	}

	return Output;
}

void FLogPP::OutputTextFile(FString LogFilePath, FString Signature)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Log Output to TextFile : " + Signature);
	OutputTextFile(LogFilePath);

}


void FLogPP::OutputTextFile(FString LogFilePath)
{
	FFileHelper::SaveStringToFile(OutputS(), *LogFilePath);

}