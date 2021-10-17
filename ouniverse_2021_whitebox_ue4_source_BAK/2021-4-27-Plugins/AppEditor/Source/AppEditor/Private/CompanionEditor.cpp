// Fill out your copyright notice in the Description page of Project Settings.


#include "CompanionEditor.h"
#include "LogPP.h"
#include "EditorAssetLibrary.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Companion.h"
#include "CompanionTable.h"

const FName UCompanionEditor::SYS = "CompanionPP";

void UCompanionEditor::ProcessCompanionData(FString Directory, UDataTable* DataTable, FLogPP& Log, int& DirNum, int& TableNum)
{
 
    DirNum = 0;
    TableNum = 0;

    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "ProcessCompanionData");
    FString Dir = "/Game/" + Directory;

    //Log->Write(HEADER, "Begin ProcessCompanionData...");
    //Log->Write(NORMAL, "Dir: "+Dir);

    if (!IsValid(DataTable))
    {
        Log.New().S(SYS).T(LogTypePP::Critical).W("The Companion DataTable was NULL.").DebugM();
        return;
    }

    Log.New().S(SYS).W("DataTable was found");

    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    TArray<FAssetData> AssetData;
    const UClass* Class = UCompanion::StaticClass();
    AssetRegistryModule.Get().GetAssetsByPath(*Dir, AssetData);
    
    if (AssetData.Num() == 0)
    {
        Log.New().S(SYS).T(LogTypePP::Critical).W("No AssetData was found in Companions Folder.").DebugM();
    }

    FString ContextString;
    TArray<FName> RowNames;
    RowNames = DataTable->GetRowNames();

    for (auto& Name : RowNames)
    {
        FCompanionTable* R = DataTable->FindRow<FCompanionTable>(Name, ContextString);
        if (R)
        {
            UClass* BPClass = R->CompanionObject.LoadSynchronous();
            UCompanion* CO = BPClass->GetDefaultObject<UCompanion>();
            CO->KID = Name;
            CO->NID = R->NID;
            CO->FirstName = R->FirstName;
            CO->LastName = R->LastName;
            CO->Strength = R->Strength;
            CO->CompanionActorClass = R->CompanionActorClass;

            FString FileName = R->CompanionObject.GetAssetName().LeftChop(2);
            GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FileName);
            UEditorAssetLibrary::SaveAsset(R->CompanionObject.ToString(), false);
            Log.New().S(SYS).W("Completed Companion: "+Name.ToString()).DebugM();

            if (!FileName.Equals(Name.ToString(),ESearchCase::IgnoreCase))
            {
                Log.New().S(SYS).T(LogTypePP::Critical).W("Name of Blueprint does not match KID: "+Name.ToString()).DebugM();
            }
        }
    }
    //UEditorAssetLibrary::SaveDirectory(Dir, false, false);
}