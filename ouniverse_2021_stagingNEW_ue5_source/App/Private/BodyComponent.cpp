// Fill out your copyright notice in the Description page of Project Settings.


#include "BodyComponent.h"
#include "KeywordComponent.h"
#include "ActraHuman.h"

UBodyComponent::UBodyComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UBodyComponent::BeginPlay()
{
	Super::BeginPlay();

	ActraHuman = Cast<AActraHuman>(GetOwner());
	ActraHuman->BodyComponent = this;
	
	
}

void UBodyComponent::Init()
{
	FName Source = FName("BodyComponent");

	for (FKeyword AutoKeyword : AutoKeywords)
	{
		ActraHuman->KeywordComponent->AddKeyword(AutoKeyword, Source);
	}

}