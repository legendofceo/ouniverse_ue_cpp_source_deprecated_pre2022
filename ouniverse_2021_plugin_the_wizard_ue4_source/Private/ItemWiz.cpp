// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemWiz.h"
#include "EditorAssetLibrary.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "ItemTable.h"
#include "ItemLib.h"

const FName UItemWiz::SYS = "ItemWiz";

void UItemWiz::BuildLib(UDataTable* DataTable, TSoftClassPtr<UItemLib> ItemLib, FString ItemDir, FWizLog& Log, FItemWizData& Output)
{
	Log.New().S(SYS).T(WizLogType::Critical).W("BuildLib()").DebugM();

    Output = FItemWizData();

    if (!IsValid(DataTable))
    {
        Log.New().S(SYS).T(WizLogType::Critical).W("Table: Null").DebugM();
        return;
    }

    Log.New().S(SYS).W("Table: Valid").DebugM();

    if (ItemLib.IsNull())
    {
        Log.New().S(SYS).T(WizLogType::Critical).W("ItemLib: Null").DebugM();
        return;
    }

    Log.New().S(SYS).W("ItemLib: Valid").DebugM();

    UClass* LibBPClass = ItemLib.LoadSynchronous();
    UItemLib* Lib = LibBPClass->GetDefaultObject<UItemLib>();
    Lib->Items.Empty();

    FString ContextString;
    TArray<FName> RowNames;
    RowNames = DataTable->GetRowNames();

    TSet<TSoftClassPtr<UItem>> SoftItems;

    FString DataTableID = "Basic";
    FString DIV = ".";

    for (auto& Name : RowNames)
    {
        FString RowNameString = Name.ToString();
        FString FullRowAddress = DataTableID + DIV + RowNameString;

        FItemTable* R = DataTable->FindRow<FItemTable>(Name, ContextString);

        Output.ItemsParsed.Add(FullRowAddress);

        if (!R)
        {
            Log.New().S(SYS).T(WizLogType::Critical).W("Something weird happened and row does not exist: " + Name.ToString()).DebugM();
            break;
        }
        else if (Name == "NewRow")
        {
            Output.InvalidRowNames.Add(FullRowAddress);
            Log.New().S(SYS).T(WizLogType::Critical).W("Row Name is Invalid: " + Name.ToString()).DebugM();
            break;
        }
        else if (R->ItemClass.IsNull())
        {
            Output.NullSoftClasses.Add(FullRowAddress);

            Log.New().S(SYS).T(WizLogType::Critical).W("ContainerClass is Null: " + Name.ToString()).DebugM();
            break;
        }
    }

    UEditorAssetLibrary::SaveAsset(ItemLib.ToString(), false);
}