// Fill out your copyright notice in the Description page of Project Settings.


#include "AppBae.h"

AAppBae::AAppBae()
{
	MythBae = CreateDefaultSubobject<UMythBae>(TEXT("MythBae"));
}

void AAppBae::BeginPlay()
{
	Super::BeginPlay();


#if UE_BUILD_DEVELOPMENT
	/**
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("InitBP");
	BEF.Add("PreStartBP");
	BEF.Add("PostStartBP");
	BEF.Go(this, ID.ToString());
	*/
#endif

}