// Fill out your copyright notice in the Description page of Project Settings.


#include "AppRemote.h"
#include "MythRemote.h"


UAppRemote::UAppRemote() : URemote()
{

}

namespace Remote
{
	UAppRemote* App = NULL;
}

void UAppRemote::BeginPlay()
{
	Super::BeginPlay();

	Remote::App = this;

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
