// Fill out your copyright notice in the Description page of Project Settings.


#include "Viz.h"
#include "Log.h"
#include "AppStream.h"
#include "ActraEx.h"
#include "ActraExHuman.h"


const FName UVizRack::SYS = "VizRack";


void UVizEx::Init(AActraEx* InActraEx)
{
	ActraEx = InActraEx;
	BeginInit();
}



void UVizExHuman::BeginInit()
{
	ActraExHuman = Cast<AActraExHuman>(ActraEx);
	BeginInitBP();
}










void UVizRack::Init()
{


}


void UVizRack::AddViz(UViz* VizToAdd)
{
	Vizs.Add(VizToAdd);
}


void UVizRack::RemoveVizBySource(UObject* Source)
{
	for (UViz* Viz : Vizs)
	{
		if (Viz->GetSource() == Source)
		{
			RemoveViz(Viz);
		}
	}
}


void UVizRack::RemoveViz(UViz* VizToRemove)
{
	Vizs.Remove(VizToRemove);
}

void UVizRack::Stream(FDelBasic Callback)
{

	TArray<FSoftObjectPath> ItemsToStream;
	TArray<TSoftClassPtr<UObject>> Softs;

	for (UViz* Viz : Vizs)
	{
		TSoftClassPtr<UVizEx> Soft = Viz->ExSoft;
		Softs.Add(Soft);
	}

	for (TSoftClassPtr<UObject> Soft : Softs)
	{
		if (Soft.IsNull())
		{
			LOG.S(SYS).T(TCRIT).W("SoftClass is NULL").DebugM();
			return;
		}
		ItemsToStream.AddUnique(Soft.ToSoftObjectPath());
	}


	UAppStream::Get()->Stream(ItemsToStream, FStreamableDelegate::CreateUObject(this,&UVizRack::Stream_Complete,Callback));

}
void UVizRack::Stream_Complete(FDelBasic Callback)
{
	Callback.Execute();
}

void UVizRack::GetAllEx(TArray<UVizEx*>& Output)
{
	UVizEx* New;

	for (UViz* Viz : Vizs)
	{
		New = NewObject<UVizEx>(this, Viz->ExSoft.Get());
		Output.Add(New);
	}
}