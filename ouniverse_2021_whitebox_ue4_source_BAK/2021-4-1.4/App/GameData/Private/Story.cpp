// Fill out your copyright notice in the Description page of Project Settings.


#include "Story.h"
#include "Blue.h"


void UStory::Init()
{
 
#if UE_BUILD_DEVELOPMENT 
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("InitBP");
	BEF.Add("PreStartBP");
	BEF.Add("PostStartBP");
	BEF.Go(this,ID.ToString());
#endif

	InitBP();

}

void UStory::PreStart()
{
	PreStartBP();
}

void UStory::PostStart(UAreaOverride* AreaOverride)
{
	PostStartBP(AreaOverride);
}