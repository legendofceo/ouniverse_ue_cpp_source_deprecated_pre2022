// Fill out your copyright notice in the Description page of Project Settings.


#include "MemEditor.h"
#include "EditorAssetLibrary.h"
#include "AssetRegistry/AssetRegistryModule.h"


void UMemEditor::BloomMemFlags(FString Directory, FAssetData AppMemBlueprint)
{
    /**
    LogR = Log;
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "BloomMemFlags");
    FString Dir = "/Game/" + Directory;

    Log->Write(HEADER, "Begin BloomMemFlags...");
    Log->Write(NORMAL, "Dir: " + Dir);


    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    TArray<FAssetData> AssetData;
    AssetRegistryModule.Get().GetAssetsByPath(*Dir, AssetData);
    
    UClass* BPClass = StaticLoadClass(AAppMem::StaticClass(), NULL, *(AppMemBlueprint.ObjectPath.ToString() + "_C"));
    AAppMem* AppMem = BPClass->GetDefaultObject<AAppMem>();
    AppMem->Mem.Bools.Empty();
    AppMem->Mem.Bytes.Empty();
    AppMem->Mem.Ints.Empty();
    AppMem->Mem.Floats.Empty();
    AppMem->Mem.Strings.Empty();

    int Bools=0;
    int Bytes=0;
    if (AssetData.Num() == 0)
    {
        Log->Write(CRITICAL, "No AssetData was found in MemFlags Folder");
    }
    else
    {

        Log->Write(NORMAL, "AssetDatas Found: " + FString::FromInt(AssetData.Num()));

        for (int i = 0; i < AssetData.Num(); i++)
        {
            UDataTable* Table = Cast<UDataTable>(AssetData[i].GetAsset());

            if (Table)
            {
                FString RowName = Table->GetRowStructName().ToString();
                FString ContextString;

                if (RowName == "MemBoolsTable")
                {
                    Bools++;
                    TArray<FName> RowNames = Table->GetRowNames();

                    for (auto& name : RowNames)
                    {
                        FMemBoolsTable* Row = Table->FindRow<FMemBoolsTable>(name, ContextString);
                        if (Row)
                        {
                            AppMem->Mem.Bools.Add(name,Row->Default);
                        }
                    }
                }
                else if (RowName == "MemBytesTable")
                {
                    Bytes++;
                    TArray<FName> RowNames = Table->GetRowNames();

                    for (auto& name : RowNames)
                    {
                        FMemBytesTable* Row = Table->FindRow<FMemBytesTable>(name, ContextString);
                        if (Row)
                        {
                            AppMem->Mem.Bytes.Add(name, Row->Default);
                        }
                    }
                }
            }
        }
    }

    Log->Write(NORMAL, "Bools Found: " + FString::FromInt(Bools));
    Log->Write(NORMAL, "Bytes Found: "+FString::FromInt(Bytes));

    UEditorAssetLibrary::SaveAsset(*(AppMemBlueprint.ObjectPath.ToString() + "_C"), false);
    */
}