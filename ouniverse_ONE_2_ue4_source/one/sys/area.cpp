// Fill out your copyright notice in the Description page of Project Settings.

#include "area.h"
#include "cell.h"
#include "level_cell.h"

FName AArea::LuaNode(TEXT("Lua"));

AArea::AArea()
{
	Lua = CreateOptionalDefaultSubobject<UAreaLua>(LuaNode);
}

UAreaLua::UAreaLua()
{
	Table.Add("get_name", FLuaValue::Function(GET_FUNCTION_NAME_CHECKED(AActraHuman, LUA_GetName)));
	LuaState = ULuaStateArea::StaticClass();
}

void AArea::Constructor()
{
	Log = FLogger("Log");
}

AArea* AArea::CreateFromData(AActor* WorldActor, Form_F* InData)
{
	AArea* Neu = WorldActor->GetWorld()->SpawnActor<AArea>(AArea::StaticClass(), FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Neu->Constructor();
	return Neu;
}

void AArea::Start()
{
	Log.Write("Area Starting.", ELogStatus::Expected);
	//CosmSpark = InAddress.Spark;
	OnStart();
	//static FLuaValue LuaRunString(UObject * WorldContextObject, TSubclassOf<ULuaState> State, FString CodeString, FString CodePath = "");
	//LoadCell();
}

void AArea::LoadCell(FName Catalyst)
{
	//ActiveCell = CellName;
	ACell* N = ACell::Create(this, Catalyst);
	Attach(N);
	//LoadedCells.Emplace(CellName, N);
	N->Load();
}