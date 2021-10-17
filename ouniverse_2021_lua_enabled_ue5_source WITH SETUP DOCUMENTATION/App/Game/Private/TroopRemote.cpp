// Fill out your copyright notice in the Description page of Project Settings.


#include "TroopRemote.h"
#include "Log.h"
#include "AppStream.h"
#include "AppWorld.h"
#include "AppController.h"
#include "ActraMem.h"
#include "ActraEx.h"
#include "Pact.h"


const FName UActraHandle::SYS = "ActraHandle";

void UActraHandle::SetActra(UActraMem* InActra)
{
	ActraMem = InActra;
}

void UActraHandle::Spawn3d(FDelBasic Callback)
{
	Spawn3dComplete = Callback;

	if (ActraMem->ActraExSoft.IsNull())
	{
		LOG.S(SYS).T(TNORM).W("ActraExSoftClass is NULL").DebugM();
	}
	else
	{		
		UAppStream::Get()->Stream(ActraMem->ActraExSoft.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UActraHandle::Spawn3d_Stream));
	}
}

void UActraHandle::Spawn3d_Stream()
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.bNoFail = true;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	ActraEx = UAppWorld::GetAppWorld()->SpawnActor<AActraEx>(ActraMem->ActraExSoft.Get(), Location, Rotation, SpawnInfo);

	FDelBasic Callback;

	Callback.BindLambda([&]()
		{
			Spawn3dComplete.Execute();
		});
	ActraEx->Init(ActraMem,Callback);

}
void UTroopRemote::ChangePact(FPact* InPact, FDelBasic Callback)
{
	Pact = InPact;
	OnChangePactComplete = Callback;
	
	SpawnQue.Reset();

	for (UActraMem* ActraMem : Pact->ActraMems)
	{
		UActraHandle* ActraHandle = NewObject<UActraHandle>(this, UActraHandle::StaticClass());
		ActraHandles.Add(ActraHandle);
		ActraHandle->SetActra(ActraMem);
		SpawnQue++;
	}



	FDelBasic IndividualCallback;
	IndividualCallback.BindLambda([&]()
		{
			if (SpawnQue.ReplyCompletes())
			{
				OnChangePactComplete.Execute();
			}
		});

	for (UActraHandle* ActraHandle : ActraHandles)
	{
		ActraHandle->Spawn3d(IndividualCallback);
	}
}

void UTroopRemote::SetTroopPosition(FTransform Transform)
{
	for (UActraHandle* ActraHandle : ActraHandles)
	{
		ActraHandle->ActraEx->SetActorLocation(Transform.GetTranslation());
	}
}

void UTroopRemote::Engage()
{
	//AAppController::Get()->Pilot(ActraHandles[Pact->PlayerActraIndex]->ActraEx);
	//AAppController::Get()->ForceCam(ActraHandles[Pact->PlayerActraIndex]->ActraEx->FollowCamera);
	ActraHandles[Pact->PlayerActraIndex]->ActraEx->Pilot();
	ActraHandles[Pact->PlayerActraIndex]->ActraEx->Connect();
}