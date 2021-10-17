// Fill out your copyright notice in the Description page of Project Settings.

#include "atlas.h"
#include "data_manager.h"
#include "file_manager.h"

#include "../key/key.h"
#include "log.h"
#include "form_type.h"
#include "../form/form_f.h"
#include "../form/actra_f.h"
#include "../form/area_f.h"
#include "../form/cell_f.h"
#include "../form/manifest_f.h"
#include "../form/bodyshape_f.h"
#include "../form/fitting_f.h"
#include "../form/skeleton_f.h"
#include "../form/wearable_f.h"
#include "../form/head_f.h"
#include "Math/UnrealMathUtility.h"


UAtlas::UAtlas()
{
	bValid = true;
};

void UAtlas::Constructor()
{
	Log = FLogger("Log");
	DataLog = FLogger("DataLog");
}

int UAtlas::NewUID()
{
	bool bTaken = true;
	int NewUID;
	while (bTaken)
	{
		NewUID = FMath::RandRange(1, 2147483646);

		if (!Lib.Contains(NewUID))
		{
			return NewUID;
		}
	}
	return -1;
}

void UAtlas::AddNewData(Form_F* NewData)
{
	Lib.Add(NewData->UID, NewData);
}

void UAtlas::AtlasFromJsonDocument(int32 NumericUID, FLogger* InLog)
{
	
	StringUID = FString::FromInt(NumericUID);
	UID = NumericUID;

	AbsolutePath = AFileManager::NormalizeDir(UDataManager::GetDataDir() + StringUID + "//");
	ContentPath = UDataManager::AtlasDirName + "//" + StringUID + "//";
	DocPath = AbsolutePath + "." + UDataManager::AtlasFileEXT;

	bool bDocExists = AFileManager::DoesFileExist(DocPath);

	if (bDocExists)
	{
		FString FileData;
		FFileHelper::LoadFileToString(FileData, *DocPath);

		if (!JsonS::IsValidJson(FileData))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "NOT VALID");
			bValid = false;
		}
		else
		{
			JsonS J;
			J.Parse(FileData);
			ShortName = "NULL";
			LongName = "NULL";
			Author = "NULL";
			Subtitle = "NULL";
			J.TryString(ShortName, "shortname");
			J.TryString(LongName, "longname");
			J.TryString(Author, "author");
			J.TryString(Subtitle, "subtitle");
			bValid = true;
		}
	}
}

void UAtlas::DataFromJson(FLogger* InLog)
{
	InLog->Write("Unpacking Atlas: "+ShortName, ELogStatus::Expected);

	FString DataFile = AbsolutePath + "." + UDataManager::AtlasDataFileEXT;
	bool bDocExists = AFileManager::DoesFileExist(DataFile);

	if (bDocExists)
	{
		FString FileData;
		FFileHelper::LoadFileToString(FileData, *DataFile);

		if (!JsonS::IsValidJson(FileData))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "NOT VALID");
			bValid = false;
		}
		else
		{
			JsonS J;
			J.Parse(FileData);
			
			JsonS JD;
			J.Try(JD, "data");

			EntriesTotal = JD.Num();
			EntriesParsed = 0;
			EntriesCreated = 0;
			EntriesApproved = 0;
			EntriesNoticed = 0;
			EntriesWarning = 0;
			EntriesCrtitical = 0;

			Form_F* NewData = nullptr;
			bool bFound;

			

			for (int i = 0; i < EntriesTotal; i++)
			{
				EntriesParsed++;
				JsonS Entry = JD[i];
				int UniversalNumber = Entry.Int(DataKeys::UniversalNumber);
				int FormType = Entry.Int(DataKeys::FormType);

				bFound = true;
				switch (FormType) {
				case UFormType::Form:
					NewData = new Form_F();
					break;
				case UFormType::Area:
					NewData = new Area_F();
					break;
				case UFormType::Cell:
					NewData = new Cell_F();
					break;
				case UFormType::Manifest:
					NewData = new Manifest_F();
					break;
				case UFormType::Actra:
					NewData = new Actra_D();
					break;
				case UFormType::Bodyshape:
					NewData = new Bodyshape_F();
					break;
				case UFormType::Head:
					NewData = new Head_F();
					break;
				case UFormType::Fitting:
					NewData = new Fitting_F();
					break;
				case UFormType::Wearable:
					NewData = new Wearable_F();
					break;
				case UFormType::Skeleton:
					NewData = new Skeleton_F();
					break;
				default:
					bFound = false;
				}

				if (bFound)
				{
					EntriesCreated++;
					NewData->BaseData(Entry, this, InLog);
					Lib.Add(UniversalNumber, NewData);
				}

			}



			Log.Write("Filling " + FString::FromInt(EntriesTotal) + " data entries.", ELogStatus::Expected);

			Form_F* Seek;
			for (int i = 0; i < EntriesTotal; i++)
			{
				if (TryData(Seek, JD.At(i).Int(DataKeys::UniversalNumber)))
				{
					int OutputStatus = Seek->FromJson(JD.At(i), &DataLog);
					if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, *Seek->SerializeAsJson()); }

					switch (OutputStatus) {
					case DataReport_D::Approved:
						EntriesApproved++;
						break;
					case DataReport_D::Noticed:
						EntriesNoticed++;
						break;
					case DataReport_D::Warned:
						EntriesWarning++;
						break;
					case DataReport_D::Critical:
						EntriesCrtitical++;
						break;
					}
				}
			}





		}
	}
}

bool UAtlas::TryData(Form_F*& Output, int InUN)
{
	if (Lib.Contains(InUN))
	{
		Output = Lib[InUN];
		return true;
	}

	return false;
}

bool UAtlas::TryAtlas(UAtlas*& Output, int UN)
{
	UDataManager* DataManager = UDataManager::Get();
	return DataManager->TryAtlas(Output, UN);
}


TArray<UAtlas*> UAtlas::GetEmptyAtlasArray()
{
	TArray<UAtlas*> Arr;
	return Arr;
}

void UAtlas::Query(TArray<UForm_F*>* ValidData, FString QueryText, UFormType* ParentType, TArray<UFormType*> FormTypeFilters)
{
	int L = Lib.Len();

	Form_F* QForm;
	UFormType* FormType;

	for (int i = 0; i < L; i++)
	{
		//UData_D* Output;
		QForm = Lib.At(i);
		FormType = UDataManager::Get()->GetFormType(QForm->FormType());

		if (FormType->IsRelative(ParentType))
		{
			if (QueryText=="" || QForm->ID.Contains(QueryText))
			{
				ValidData->Add(QForm->ToUObject());
			}
		}
	}
}

void UAtlas::Save()
{
	JsonS J;
	//J.Add("shortname",ShortName);
	//J.Add("longname",LongName);
	//J.Add("author",Author);
	//J.Add("subtitle",Subtitle);

	
	int L = Lib.Len();

	ArrayC<JsonS> Array;

	for (int i = 0; i < L; i++)
	{
		Array.Add(Lib.At(i)->ToJson());
	}

	J.Add("data", Array);

	FString DataFile = AbsolutePath + "." + UDataManager::AtlasDataFileEXT;
	FFileHelper::SaveStringToFile(J.Serialize(), *DataFile);
}