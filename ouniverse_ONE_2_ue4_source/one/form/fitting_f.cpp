// Fill out your copyright notice in the Description page of Project Settings.

#include "fitting_f.h"


int Fitting_F::FromJson(JsonS* J, FLogger* Log)
{
	ID = J->String(DataKeys::ID);

	/**
	JsonS BodyshapeMapJ = J.String(DataKeys::Wearable::BodyshapeMap);

	for (const TPair<FString, TSoftClassPtr<USkeletalMesh>>& Result : BodyshapeMap)
	{
		Result.Key;
		Result.Value;
	}
	*/
	return DataReport_D::Approved;
}