// Fill out your copyright notice in the Description page of Project Settings.

#include "log.h"



void FLogger::Write(FString Text, TEnumAsByte<ELogStatus> Status)
{
	Entries.Add(FLogEntry(Text, Status));
}