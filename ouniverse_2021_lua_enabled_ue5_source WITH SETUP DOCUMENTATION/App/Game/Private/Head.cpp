// Fill out your copyright notice in the Description page of Project Settings.

#include "Head.h"
#include "Log.h"
#include "AppStream.h"
#include "Chassis.h"
#include "Viz.h"


const FName UHeadHuman::SYS = "HeadHuman";


void UHead::Init(UVizRack* InVizRack)
{
	VizRack = InVizRack;
	BeginInit();
}




void UHeadHuman::BeginInit()
{
	if (HeadVizBP == nullptr)
	{
		LOG.S(SYS).T(TCRIT).W("HeadViz is null").DebugM();
		return;
	}

	UViz* HeadViz = NewObject<UViz>(this, HeadVizBP.Get());
	HeadViz->SetSource(this);
	VizRack->AddViz(HeadViz);

}

void UHeadHuman::StreamChassis(FDelBasic Callback)
{

	if (ChassisSoft.IsNull())
	{
		LOG.S(SYS).T(TCRIT).W("Chassis is NULL").DebugM();
		return;
	}

	UAppStream::Get()->Stream(ChassisSoft.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UHeadHuman::StreamChassis_Complete, Callback));
}

void UHeadHuman::StreamChassis_Complete(FDelBasic Callback)
{
	Callback.Execute();
}

UChassis* UHeadHuman::GetChassis()
{
	return NewObject<UChassis>(this, ChassisSoft.Get());
}