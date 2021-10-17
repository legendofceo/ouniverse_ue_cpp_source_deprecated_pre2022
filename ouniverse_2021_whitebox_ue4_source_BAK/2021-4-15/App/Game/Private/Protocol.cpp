// Fill out your copyright notice in the Description page of Project Settings.


#include "Protocol.h"


UProtocol::UProtocol()
{

}

void UProtocol::InitComplete()
{
	bInit = true;
	OnInitComplete.Broadcast(this);
}