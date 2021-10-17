// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "ItemBaseTable.h"

UItemBase::UItemBase()
{

}

void UItemBase::DataFromTable(FName RowKey, FTableRowBase* TableData)
{
	FItemBaseTable* R = static_cast<FItemBaseTable*>(TableData);
	Description = R->Description;
}