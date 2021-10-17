// Fill out your copyright notice in the Description page of Project Settings.


#include "Log.h"
#include "Components/ActorComponent.h"

DEFINE_LOG_CATEGORY(LogApp);

const float ULogger::DebugMessageDefaultDuration = 8.0f;
const FColor ULogger::DebugMessageDefaultColor = FColor::Green;

namespace Log
{
	ULogger* Master;
}


ULogger::ULogger()
{
	Log::Master = this;
}

ULogger* ULogger::Get()
{
	return Log::Master;
}

//#if !(UE_BUILD_SHIPPING)

//#endif


FLogEntry& FLogEntry::W(FString InText)
{
	Text = InText;

#if (!UE_BUILD_SHIPPING)
	switch (LogType) {
	case ELogType::Normal:
		UE_LOG(LogApp, Log, TEXT("%s"), *OutputS());
		break;
	case ELogType::Warning:
		UE_LOG(LogApp, Warning, TEXT("%s"), *OutputS());
		break;
	case ELogType::Critical:
		UE_LOG(LogApp, Error, TEXT("%s"), *OutputS());
		break;
	}

#endif

	return *this;
}

FLogEntry& FLogEntry::S(FName InSystem)
{
	System = InSystem;
	return *this;
}


FLogEntry& FLogEntry::I(FName InID)
{
	ID = InID;
	return *this;
}

FLogEntry& FLogEntry::T(ELogType InLogType)
{
	LogType = InLogType;
	return *this;
}

FLogEntry& FLogEntry::V(ELogVerb InLogVerbosity)
{
	LogVerbosity = InLogVerbosity;
	return *this;
}

FLogEntry& FLogEntry::N(UActorComponent* InOBJ)
{

	ENetMode NM = InOBJ->GetNetMode();

	switch (NM) {
	case ENetMode::NM_Standalone:
		NetMode = ENetModeII::Standalone;
		break;
	case ENetMode::NM_Client:
		NetMode = ENetModeII::Client;
		break;
	case ENetMode::NM_DedicatedServer:
		NetMode = ENetModeII::Dedicated;
		break;
	case ENetMode::NM_ListenServer:
		NetMode = ENetModeII::Listen;
		break;
	}

	return *this;
}

FLogEntry& FLogEntry::DebugM()
{
	switch (LogType) {
	case ELogType::Normal :
		return DebugM(FColor::Green, ULogger::DebugMessageDefaultDuration);
		break;
	case ELogType::Warning:
		return DebugM(FColor::Yellow, ULogger::DebugMessageDefaultDuration);
		break;
	case ELogType::Critical:
		return DebugM(FColor::Orange, ULogger::DebugMessageDefaultDuration);
		break;
	default:

		return DebugM(ULogger::DebugMessageDefaultColor, ULogger::DebugMessageDefaultDuration);
	}

}

FLogEntry& FLogEntry::DebugM(FColor Color, float Duration)
{
	
	GEngine->AddOnScreenDebugMessage(-1, Duration, Color, *OutputS());
	return *this;
}

FString FLogEntry::OutputS()
{
	FString Output = "";

	Output += System.ToString();

	if (!ID.IsNone())
	{
		Output += (" #" + ID.ToString());
	}

	Output += " | ";

	switch (NetMode) {
	case ENetModeII::Standalone:
		Output += "SA | ";
		break;
	case ENetModeII::Client:
		Output += ("Client "+FString::FromInt(NetIndex))+" | ";
		break;
	case ENetModeII::Dedicated:
		Output += "SERVER_D | ";
		break;
	case ENetModeII::Listen:
		Output += "SERVER | ";
		break;
	}

	Output += Text;
	return Output;
}

FLogEntry& ULogger::New()
{
	FLogEntry NewEntry = FLogEntry();
	NewEntry.Time = FPlatformTime::Seconds();
	return Entries.Add_GetRef(NewEntry);
}

FString ULogger::OutputS()
{
	FString Output;
	for (FLogEntry LE : Entries)
	{
		Output+=LE.OutputS();
		Output += LINE_TERMINATOR;
	}
	
	return Output;
}



void ULogger::LogBP(FString Text, FName System, FName ID, ELogType Type, ELogVerb Verbosity)
{
	FLogEntry Entry = ULogger::Get()->New();
	Entry.S(System).T(Type).V(Verbosity);

	if (!ID.IsNone())
	{
		Entry.I(ID);
	}

	Entry.W(Text);
}


void ULogger::LogPrintScreenBP(FString Text, FName System, FName ID, ELogType Type, ELogVerb Verbosity)
{
	FLogEntry Entry = ULogger::Get()->New();
	Entry.S(System).T(Type).V(Verbosity);

	if (!ID.IsNone())
	{
		Entry.I(ID);
	}

	Entry.W(Text).DebugM();
}

void ULogger::OutputTextFile(FString LogFilePath, FString Signature)
{
	GEngine->AddOnScreenDebugMessage(-1, ULogger::DebugMessageDefaultDuration, FColor::Green, "Log Output to TextFile : "+Signature);
	OutputTextFile(LogFilePath);

}


void ULogger::OutputTextFile(FString LogFilePath)
{
	FFileHelper::SaveStringToFile(OutputS(), *LogFilePath);

}