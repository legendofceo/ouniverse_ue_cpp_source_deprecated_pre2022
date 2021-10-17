// Fill out your copyright notice in the Description page of Project Settings.

#include "Hair.h"
#include "Log.h"
#include "AppStream.h"
#include "Chassis.h"
#include "Viz.h"


const FName UHairHuman::SYS = "HairHuman";


void UHair::Init(UVizRack* InVizRack)
{
	VizRack = InVizRack;
	BeginInit();
}




void UHairHuman::BeginInit()
{
	if (HairVizBP == nullptr)
	{
		LOG.S(SYS).T(TCRIT).W("HairViz is null").DebugM();
		return;
	}

	UViz* HairViz = NewObject<UViz>(this, HairVizBP.Get());
	HairViz->SetSource(this);
	VizRack->AddViz(HairViz);

}

void UHairHuman::StreamChassis(FDelBasic Callback)
{

	if (ChassisSoft.IsNull())
	{
		LOG.S(SYS).T(TCRIT).W("Chassis is NULL").DebugM();
		return;
	}

	UAppStream::Get()->Stream(ChassisSoft.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UHairHuman::StreamChassis_Complete, Callback));
}

void UHairHuman::StreamChassis_Complete(FDelBasic Callback)
{
	Callback.Execute();
}

UChassis* UHairHuman::GetChassis()
{
	return NewObject<UChassis>(this, ChassisSoft.Get());
}