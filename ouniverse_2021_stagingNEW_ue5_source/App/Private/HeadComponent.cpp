// Fill out your copyright notice in the Description page of Project Settings.


#include "HeadComponent.h"
#include "KeywordComponent.h"
#include "ActraHuman.h"



UHeadComponent::UHeadComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHeadComponent::BeginPlay()
{
	Super::BeginPlay();

	ActraHuman = Cast<AActraHuman>(GetOwner());
	ActraHuman->HeadComponent = this;


}

void UHeadComponent::Init()
{
	FName Source = FName("HeadComponent");

	for (FKeyword AutoKeyword : AutoKeywords)
	{
		ActraHuman->KeywordComponent->AddKeyword(AutoKeyword, Source);
	}

}