// Fill out your copyright notice in the Description page of Project Settings.



#include "EditorMarker.h"
#include "Materials/MaterialInstanceDynamic.h"

UEditorMarker::UEditorMarker()
{

}

void UEditorMarker::Init()
{
	UMaterialInstanceDynamic* DynaMat = CreateDynamicMaterialInstance(0, GetStaticMesh()->GetMaterial(0));
	DynaMat->SetVectorParameterValue("Primary", FLinearColor::Blue);
	GetStaticMesh()->SetMaterial(0, DynaMat);
}