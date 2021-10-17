// Fill out your copyright notice in the Description page of Project Settings.


#include "Log.h"

void FLogger::SetID(FString InID)
{
	ID = InID;
}

void FLogger::Write(TEnumAsByte<ELogAuth> Auth, TEnumAsByte<ELogStatus> Status, TEnumAsByte<ELogVerb> Verbosity, uint8 Indent, bool DataList, FString Text)
{
	FLogEntry NewEntry = FLogEntry();
	NewEntry.Auth = Auth;
	NewEntry.Status = Status;
	NewEntry.Verbosity = Verbosity;
	NewEntry.Indent = Indent;
	NewEntry.Text = Text;
	NewEntry.DataList = DataList;
	NewEntry.Time = FPlatformTime::Seconds();
	Entries.Add(NewEntry);

	UE_LOG(AppLog, Warning, TEXT("%s"), *Text);
}