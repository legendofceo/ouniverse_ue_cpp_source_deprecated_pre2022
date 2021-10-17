// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveMutual.h"

FText IInteractiveMutual::GetInteractiveName_Implementation()
{
	return FText::FromString("TestName");
}

void IInteractiveMutual::GetInteractiveUi_Implementation(const FAnythingUiFetch& Fetch)
{

}