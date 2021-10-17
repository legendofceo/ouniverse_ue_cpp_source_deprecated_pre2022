// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorHuman.h"
#include "KitRove.h"


void UBehaviorHuman::Init(AActraExHuman* InActraExHuman)
{

	ActraExHuman =  InActraExHuman;
	KitRove = NewObject<UKitRove>(this, UKitRove::StaticClass());
	KitRove->Init(ActraExHuman);

}

void UBehaviorHuman::Connect()
{
	KitRove->Connect();
}

void UBehaviorHuman::Disconnect()
{
	KitRove->Disconnect();
}