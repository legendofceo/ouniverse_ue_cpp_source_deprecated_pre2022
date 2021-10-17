// Fill out your copyright notice in the Description page of Project Settings.


#include "ContainerWiz.h"
#include "EditorAssetLibrary.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "ContainerTable.h"
#include "Container.h"
#include "ContainerLib.h"

const FName UContainerWiz::SYS = "ContainerWiz";

void UContainerWiz::BuildLib(UDataTable* DataTable, TSoftClassPtr<UContainerLib> ContainerLib, FString ContainerDir, UPARAM(ref) FWizLog& Log, FContainerWizData& Output)
{
    
	Log.New().S(SYS).T(WizLogType::Critical).W("BuildLib()").DebugM();

    int TotalParsed = 0;
    int TotalFinished = 0;
    int TotalRenamed = 0;
    int NullSoftClasses = 0;
    int InvalidNames = 0;
    int DuplicateMemKeys = 0;
    int DuplicateSofts = 0;
    int AssetsNotInTable = 0;

    if (!IsValid(DataTable))
    {
        Log.New().S(SYS).T(WizLogType::Critical).W("Table: Null").DebugM();
        return;
    }

    Log.New().S(SYS).W("Table: Valid").DebugM();

    if (ContainerLib.IsNull())
    {
        Log.New().S(SYS).T(WizLogType::Critical).W("ContainerLib: Null").DebugM();
        return;
    }

    Log.New().S(SYS).W("ContainerLib: Valid").DebugM();

    UClass* LibBPClass = ContainerLib.LoadSynchronous();
    UContainerLib* Lib = LibBPClass->GetDefaultObject<UContainerLib>();
    Lib->ContainerClasses.Empty();

    FString ContextString;
    TArray<FName> RowNames;
    RowNames = DataTable->GetRowNames();

    TSet<int> MemKeys;
    TSet<TSoftClassPtr<UContainer>> SoftContainers;

    for (auto& Name : RowNames)
    {
        FContainerTable* R = DataTable->FindRow<FContainerTable>(Name, ContextString);
        TotalParsed++;

        if (!R)
        {
            Log.New().S(SYS).T(WizLogType::Critical).W("Something weird happened and row does not exist: " + Name.ToString()).DebugM();
            break;
        }
        else if (Name == "NewRow")
        {
            InvalidNames++;
            Log.New().S(SYS).T(WizLogType::Critical).W("Row Name is Invalid: " + Name.ToString()).DebugM();
            break;
        }
        else if (R->ContainerClass.IsNull())
        {
            NullSoftClasses++;
            Log.New().S(SYS).T(WizLogType::Critical).W("ContainerClass is Null: " + Name.ToString()).DebugM();
            break;
        }
                
        /* Has the softclass already been seen in the table?
        * Entries should never share the same softclass!
        */
        if (SoftContainers.Contains(R->ContainerClass))
        {
            Log.New().S(SYS).T(WizLogType::Critical).W("Duplicate ContainerClasses: " + Name.ToString()).DebugM();
            DuplicateSofts++;
            break;
        }
        SoftContainers.Add(R->ContainerClass);

        UClass* BPClass = R->ContainerClass.LoadSynchronous();
        UContainer* DO = BPClass->GetDefaultObject<UContainer>();
        DO->MemKey = R->MemKey;
        DO->MemType = R->MemType;

        /* Has the MemKey already been seen in the table?
        * Entries should never share the same MemKey!
        */
        if (MemKeys.Contains(DO->MemKey))
        {
            Log.New().S(SYS).T(WizLogType::Critical).W("Duplicate MemKey: " + Name.ToString()+ " | "+FString::FromInt(DO->MemKey)).DebugM();
            DuplicateMemKeys++;
        }
        else
        {
            MemKeys.Add(DO->MemKey);
        }

        /* Is the Asset name the same as the TableKey?
        * This is for organizational purposes only to keep the project tidy
        */
        FString FileName = R->ContainerClass.GetAssetName().LeftChop(2);
        if (!FileName.Equals(Name.ToString(), ESearchCase::IgnoreCase))
        {
            FString OldPathName = R->ContainerClass.ToString();
            FString NewPathName = OldPathName.Replace(*FileName, *Name.ToString(), ESearchCase::IgnoreCase).LeftChop(2);
            Log.New().S(SYS).T(WizLogType::Warning).W("Name of Blueprint does not match Key: " + Name.ToString()).DebugM();
            UEditorAssetLibrary::RenameAsset(OldPathName, NewPathName);
            UEditorAssetLibrary::SaveAsset(NewPathName, false);
            TotalRenamed++;
        }
        else
        {
            UEditorAssetLibrary::SaveAsset(R->ContainerClass.ToString(), false);
        }

        TotalFinished++;
        Lib->ContainerClasses.Add(R->ContainerClass);

        Log.New().S(SYS).W("Completed Container: " + Name.ToString()).DebugM();
    }

    UEditorAssetLibrary::SaveAsset(ContainerLib.ToString(), false);
    

    /* Scan the containers folder and compare the names with the list.
    * This is to ensure all assets are included in the list.
    */
    

    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    TArray<FAssetData> AssetDatas;
    const UClass* Class = UContainer::StaticClass();
    AssetRegistryModule.Get().GetAssetsByPath(*ContainerDir, AssetDatas, true);

    if (AssetDatas.Num() == 0)
    {
        Log.New().S(SYS).T(WizLogType::Critical).W("No UContainers were found in Directory.").DebugM();
    }

    for (FAssetData AssetData : AssetDatas)
    {
        Log.New().S(SYS).W(AssetData.AssetName.ToString()).DebugM();

        if(!RowNames.Contains(AssetData.AssetName))
        {
            Log.New().S(SYS).W("ASSET MISSING FROM TABLE: "+AssetData.AssetName.ToString()).DebugM();
            AssetsNotInTable++;
        }
    }

    Log.New().S(SYS).W("BuildLib Complete").DebugM();
    Log.New().S(SYS).W("Parsed: "+FString::FromInt(TotalParsed)).DebugM();
    Log.New().S(SYS).W("Finished: " + FString::FromInt(TotalFinished)).DebugM();
    Log.New().S(SYS).W("Renamed: " + FString::FromInt(TotalRenamed)).DebugM();
    Log.New().S(SYS).W("InvalidNames: " + FString::FromInt(InvalidNames)).DebugM();
    Log.New().S(SYS).W("DuplicateMemKeys: " + FString::FromInt(DuplicateMemKeys)).DebugM();
    Log.New().S(SYS).W("DuplicateSofts: " + FString::FromInt(DuplicateSofts)).DebugM();
    Log.New().S(SYS).W("AssetsNotInTable: " + FString::FromInt(AssetsNotInTable)).DebugM();
}