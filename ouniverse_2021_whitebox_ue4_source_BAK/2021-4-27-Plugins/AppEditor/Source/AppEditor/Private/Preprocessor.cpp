// Fill out your copyright notice in the Description page of Project Settings.


#include "Preprocessor.h"
#include "EditorAssetLibrary.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "LogPP.h"

#include "GameData.h"

#include "EquipmentSlotTable.h"
#include "EquipmentSlotEnum.h"
#include "EquipmentSlotCodes.h"

void UPreprocessor::ProcessEquipmentSlots(TSoftClassPtr<UGameData> GameDataBP, UDataTable* DataTable, UPARAM(ref) FLogPP& Log, int& EquipmentSlotsNum)
{
    EquipmentSlotsNum = 0;
    FName SYS = "ProcessEquipmentSlots";

    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "ProcessEquipmentSlots");

    //Log->Write(HEADER, "Begin ProcessCompanionData...");
    //Log->Write(NORMAL, "Dir: "+Dir);

    if (!IsValid(DataTable))
    {
        Log.New().S(SYS).T(LogTypePP::Critical).W("The EquipmentSlots DataTable was NULL.").DebugM();
        return;
    }

    Log.New().S(SYS).W("DataTable was found");

    UClass* BPClass = GameDataBP.LoadSynchronous();
    UGameData* CO = BPClass->GetDefaultObject<UGameData>();

    FString ContextString;
    TArray<FName> RowNames;
    RowNames = DataTable->GetRowNames();


    TSet<EquipmentSlotEnum> FoundEnums;
    bool bIsAlreadyInSet = false;


    for (auto& Name : RowNames)
    {
        FEquipmentSlotTable* R = DataTable->FindRow<FEquipmentSlotTable>(Name, ContextString);
        if (R)
        {
            FoundEnums.Add(R->Slot, &bIsAlreadyInSet);

            if (bIsAlreadyInSet)
            {
                Log.New().S(SYS).T(LogTypePP::Critical).W("Multiple Rows had the same slot enum.").DebugM();
                return;
            }
        }
    }

    CO->EquipmentSlotBases.Empty();

    for (auto& Name : RowNames)
    {
        FEquipmentSlotTable* R = DataTable->FindRow<FEquipmentSlotTable>(Name, ContextString);
        if (R)
        {
            int Code = UEquipmentSlotCodes::FromEnum(R->Slot);

            if (Code == 0)
            {
                Log.New().S(SYS).T(LogTypePP::Critical).W("A slot code was 0: "+Name.ToString()).DebugM();
            }

            if (CO->EquipmentSlotBases.Contains(Code))
            {
                Log.New().S(SYS).T(LogTypePP::Critical).W("The library already contained this code: " + Name.ToString()).DebugM();
            }

            FEquipmentSlotBase ESB = FEquipmentSlotBase();
            ESB.Name = R->Name;
            ESB.Desc = R->Desc;
            ESB.Icon = R->Icon;
            CO->EquipmentSlotBases.Add(Code,ESB);
        }
    }

    UEditorAssetLibrary::SaveAsset(GameDataBP.ToString(), false);
}