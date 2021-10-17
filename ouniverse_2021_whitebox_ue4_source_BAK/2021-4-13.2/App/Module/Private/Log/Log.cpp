// Fill out your copyright notice in the Description page of Project Settings.


#include "Log.h"


namespace Logger
{
	FLoggerMaster* Master;
}

void FLoggerMaster::SetMasterLogger(FLoggerMaster* LoggerMaster)
{
	Logger::Master = LoggerMaster;
}

void FLoggerMaster::Add(FLogEntry* LogEntry)
{
	EntryCount++;
	Entries.Add(LogEntry);

#if !(UE_BUILD_SHIPPING)
	EntriesCopy.Add(*LogEntry);
#endif

}

FString FLogger::Print()
{

}

FLogEntry& FLogEntry::Type(ELogType InLogType)
{
	LogType = InLogType;
	return *this;
}

FLogEntry& FLogEntry::UE()
{
	UE_LOG(AppLog, Warning, TEXT("%s"), *Text);
	return *this;
}

FLogEntry& FLogEntry::DM()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, *Text);
	return *this;
}

void FLogger::SetID(FString InID)
{
	ID = InID;
}

FLogEntry& FLogger::W(FString Text)
{
	FLogEntry NewEntry = FLogEntry();
	NewEntry.Text = Text;
	NewEntry.Time = FPlatformTime::Seconds();

	//NewEntry.Auth = Auth;
	//NewEntry.Remote = Remote;
	//NewEntry.Verbosity = Verbosity;
	//NewEntry.Indent = Indent;
	
	//NewEntry.DataList = DataList;
	
	//FLogEntry* OutEntry = &Entries.Add_GetRef(NewEntry);

	Logger::Master->Add(&NewEntry);
	return Entries.Add_GetRef(NewEntry);
}