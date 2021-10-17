// Fill out your copyright notice in the Description page of Project Settings.


#include "Log.h"
#include "Components/ActorComponent.h"

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
	return DebugM(FColor::Magenta);
}

FLogEntry& FLogEntry::DebugM(FColor Color)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, Color, *Text);
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

void ULogger::OutputTextFile(FString Signature)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Log Output to TextFile : "+Signature);
	OutputTextFile();

}


void ULogger::OutputTextFile()
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	FString MyDocs = FPlatformProcess::UserDir();

	FString GameFolder = MyDocs + "Etreia//";
	FPaths::NormalizeDirectoryName(GameFolder);
	PlatformFile.CreateDirectoryTree(*GameFolder);

	FString LogFile = GameFolder += "log.txt";
	FFileHelper::SaveStringToFile(OutputS(), *LogFile);

}