// Fill out your copyright notice in the Description page of Project Settings.


#include "AnythingUiFetch.h"


void UAnythingUiFetchUtil::FetchAnythingUiCompleteBP(FAnythingUiFetch& Fetch, UAnythingUi* AnythingUi)
{
	Fetch.AnythingUi = AnythingUi;
	Fetch.Func.Execute(Fetch);
}