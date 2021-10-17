// Fill out your copyright notice in the Description page of Project Settings.


#include "App/DataLib.h"

#include "App/DataPack.h"

#include "Interface/String.h"
#include "Interface/Json.h"

#include "Misc/Paths.h"

namespace GlobalDataLib
{
	bool Exists = false;
	DataLibC* Object;
}

void UDataLib::Test()
{
	/**
		if(!GlobalDataLib::Exists)
		{
			GlobalDataLib::Object = new DataLibC();
			GlobalDataLib::Exists = true;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Loaded!"));
		}
		*/

}


DataLibC::DataLibC()
{
	DataPackC* Neu = new DataPackC(StringC(FPaths::ProjectContentDir() + "atlas.txt").ToChar());
	Lib_.Add(Neu->U(),Neu);
}

DataLibC* DataLibC::Get()
{
	if (!GlobalDataLib::Exists)
	{
		GlobalDataLib::Object = new DataLibC();
		GlobalDataLib::Exists = true;
	}

	return GlobalDataLib::Object;
}

bool DataLibC::TryData(int InPack, int InData, DataD*& InRef)
{
	DataPackC* Pack_;
	if (Lib_.Try(InPack, Pack_))
	{

		if (Pack_->Lib_.Try(InData, InRef))
		{
			return true;
		}
	}

	return false;
}
