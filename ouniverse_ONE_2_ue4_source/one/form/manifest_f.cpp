// Fill out your copyright notice in the Description page of Project Settings.

#include "manifest_f.h"
#include "spawn_f.h"

int Manifest_F::FromJson(JsonS* J, FLogger* Log)
{
	JsonS SpawnsJson = J->Key(DataKeys::Manifest::Spawns);
	int L = SpawnsJson.Num();

	for (int i = 0; i < L; i++)
	{
		Spawn_F Spawn;
		Spawn.FromJson(SpawnsJson[i], Atlas, Log);
		Spawns.Add(Spawn);
	}

	return DataReport_D::Approved;
}

JsonS* Manifest_F::ToJson(JsonS* J)
{
	Form_F::ToJson(J);

	int L = Spawns.Len();

	ArrayC<JsonS> SpawnArr;
	for (int i = 0; i < L; i++)
	{
		SpawnArr.Add(Spawns[i].ToJson());
	}

	J->Add(DataKeys::Manifest::Spawns, SpawnArr);
	return J;

}