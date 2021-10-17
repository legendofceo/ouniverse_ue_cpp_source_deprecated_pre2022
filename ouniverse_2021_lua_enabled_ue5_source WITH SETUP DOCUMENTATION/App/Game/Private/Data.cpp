// Fill out your copyright notice in the Description page of Project Settings.


#include "Data.h"
#include "Log.h"
#include "AppStream.h"
#include "AppWorld.h"

#include "Area.h"
#include "ActraMem.h"

#include "HeroData.h"

const FName UData::SYS = "Data";

namespace Global
{
	UData* Data = nullptr;
}

UData* UData::Get()
{
	return Global::Data;
}

void UData::GetBP(UData*& Data)
{
	Data = Global::Data;
}

UData::UData()
{
	Global::Data = this;
}

void UData::ResetBP(const FDelDynamic& Event)
{
	OnResetComplete = Event;
	Reset();
}

void UData::Reset()
{
	if (DataInitializerSoft.IsNull())
	{
		LOG.S(SYS).T(TCRIT).W("DataInitializer is NULL").DebugM();
		return;
	}

	UAppStream::Get()->Stream(DataInitializerSoft.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UData::Reset_DataInitializerStreamed));
}


void UData::Reset_DataInitializerStreamed()
{
	DataInitializer = NewObject<UDataInitializer>(this, DataInitializerSoft.Get());

	ActraMems.Reset();
	UActraMem* ActraMem = nullptr;

	ActraCount = 0;
	for (TSubclassOf<UActraMem> ActraClass : DataInitializer->ActraMemSofts)
	{
		ActraMem = NewObject<UActraMem>(UAppWorld::GetAppWorld(), ActraClass.Get());
		if (ActraMems.Contains(ActraMem->KeyID))
		{
			LOG.S(SYS).T(TCRIT).W("Actra ID Already Registered: "+ActraMem->KeyID.ToString()).DebugM();
		}
		else
		{		
			ActraCount++;
			ActraMems.Add(ActraMem->KeyID, ActraMem);

			if (!ActraMem->Validate())
			{
				return;
			}

			ActraMem->Init();
		}
	}

	Areas.Reset();
	AreaCount = 0;
	UArea* Area = nullptr;
	for (TSubclassOf<UArea> AreaClass : DataInitializer->AreaSofts)
	{
		Area = NewObject<UArea>(UAppWorld::GetAppWorld(), AreaClass.Get());
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, AreaSoft.GetAssetName());
		FName Test = "somecoolname";

		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(sizeof(AreaSoft)));
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(sizeof(Test)));
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(Test.GetResourceSizeBytes(EResourceSizeMode::EstimatedTotal)));
		if (Areas.Contains(Area->KeyID))
		{
			LOG.S(SYS).T(TCRIT).W("Actra ID Already Registered: " + Area->KeyID.ToString()).DebugM();
		}
		else
		{
			AreaCount++;
			Areas.Add(Area->KeyID, Area);
		}
	}

	if (!DataInitializer->HeroDataTable)
	{
		LOG.S(SYS).T(TCRIT).W("HeroDataTable is null").DebugM();
		return;
	}

	FString ContextString;
	TArray<FName> RowNames;
	RowNames = DataInitializer->HeroDataTable->GetRowNames();

	for (auto& Name : RowNames)
	{
		FHeroData* Row = DataInitializer->HeroDataTable->FindRow<FHeroData>(Name, ContextString);
		if (Row)
		{
			Heroes.Add(Name, *Row);
		}
	}

	//ActraMem = NewObject<UActraMem>(this, DataInitializer->ActraMemSofts[0].Get());
	//GeneratedActraes.Add(0, ActraMem);



	FPact& NewPact = Pacts.Add(0,FPact());

	NewPact.AddActra(ActraMems.FindRef("fione"));

	OnResetComplete.Execute();
}

TArray<FHeroData> UData::GetActiveHeroes()
{
	TArray<FHeroData> ActiveHeroes;

	for (const TPair<FName, FHeroData>& Pair : Heroes)
	{
		if (Pair.Value.bActive == true)
		{
			ActiveHeroes.Add(Pair.Value);
		}
	}

	return ActiveHeroes;
}