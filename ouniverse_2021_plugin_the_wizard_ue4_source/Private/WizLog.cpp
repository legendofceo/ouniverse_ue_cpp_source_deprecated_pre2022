// Fill out your copyright notice in the Description page of Project Settings.


#include "WizLog.h"


FWizLogEntry& FWizLogEntry::W(FString InText)
{
	Text = InText;
	return *this;
}

FWizLogEntry& FWizLogEntry::S(FName InSystem)
{
	System = InSystem;
	return *this;
}


FWizLogEntry& FWizLogEntry::I(FName InID)
{
	ID = InID;
	return *this;
}

FWizLogEntry& FWizLogEntry::T(WizLogType InWizLogType)
{
	Type = InWizLogType;
	return *this;
}

FWizLogEntry& FWizLogEntry::DebugM()
{
	return DebugM(FColor::Magenta);
}

FWizLogEntry& FWizLogEntry::DebugM(FColor Color)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, Color, *OutputS());
	return *this;
}

FString FWizLogEntry::OutputS()
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

FWizLogEntry& FWizLog::New()
{
	FWizLogEntry NewEntry = FWizLogEntry();
	NewEntry.Time = FPlatformTime::Seconds();
	return Entries.Add_GetRef(NewEntry);
}

FString FWizLog::OutputS()
{
	FString Output;
	for (FWizLogEntry LE : Entries)
	{
		Output += LE.OutputS();
		Output += LINE_TERMINATOR;
	}

	return Output;
}

void FWizLog::OutputTextFile(FString WizLogFilePath, FString Signature)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "WizLog Output to TextFile : " + Signature);
	OutputTextFile(WizLogFilePath);

}


void FWizLog::OutputTextFile(FString WizLogFilePath)
{
	FFileHelper::SaveStringToFile(OutputS(), *WizLogFilePath);

}