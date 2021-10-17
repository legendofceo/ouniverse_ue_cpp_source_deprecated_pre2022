// Fill out your copyright notice in the Description page of Project Settings.


#include "MapEditor.h"
#include "EditorAssetLibrary.h"
#include "AssetRegistry/AssetRegistryModule.h"

void UMapEditor::BloomMapData(FString Directory, FAssetData AppMemBlueprint, int& MapsAdded)
{
    /**
    MapsAdded = 0;
    int MapsFound = 0;

    LogR = Log;
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "BloomMapData");
    FString Dir = "/Game/" + Directory;

    Log->Write(HEADER, "Begin BloomMapData...");
    Log->Write(NORMAL, "Dir: " + Dir);

    //FString GetPath = ULibUtils::LibAssetPath;

    UClass* BPClass = StaticLoadClass(AAppMem::StaticClass(), NULL, *(AppMemBlueprint.ObjectPath.ToString() + "_C"));
    AAppMem* AppMem = BPClass->GetDefaultObject<AAppMem>();

    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    TArray<FAssetData> AssetData;
    AssetRegistryModule.Get().GetAssetsByPath(*Dir, AssetData, true);


    if (AssetData.Num() == 0)
    {
        Log->Write(CRITICAL,"The Path is most likely incorrect.No Data Was Found");
    }
    else
    {

        Log->Write(NORMAL, "AssetDatas Found: " + FString::FromInt(AssetData.Num()));

        for (int i = 0; i < AssetData.Num(); i++)
        {
            UWorld* Level = Cast<UWorld>(AssetData[i].GetAsset());
            MapsFound++;

            if (Level)
            {
                FName MapName = AssetData[i].AssetName;
                TSoftObjectPtr<UWorld> MapPtr = TSoftObjectPtr<UWorld>(AssetData[i].ToSoftObjectPath());
                AppMem->Maps.Add(MapName,MapPtr);
                MapsAdded++;
                Log->Write(VERBOSE, "Map Added: " + MapName.ToString());
            }
            else
            {
                Log->Write(CRITICAL, "Something weird happened in BloomMapData");
            }
        }
    }

    if (MapsFound == MapsAdded)
    {
        Log->Write(NORMAL, "Added " + FString::FromInt(MapsAdded) + " Maps");
    }
    else
    {
        Log->Write(WARNING, "Added " + FString::FromInt(MapsAdded) + " Maps but "+FString::FromInt(MapsFound)+" total maps were in the directory");
    }

    UEditorAssetLibrary::SaveAsset(*(AppMemBlueprint.ObjectPath.ToString() + "_C"), false);
    */
}