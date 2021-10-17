// Fill out your copyright notice in the Description page of Project Settings.


#include "BodyMemHuman.h"
#include "Log.h"
#include "AppStream.h"
#include "Chassis.h"
#include "Viz.h"


const FName UBodyMemHuman::SYS = "BodyMemHuman";

void UBodyMemHuman::BeginInit()
{
	if (ChestVizBP == nullptr || LegsVizBP == nullptr || HandsVizBP == nullptr || FeetVizBP == nullptr)
	{
		LOG.S(SYS).T(TCRIT).W("BodyViz is null").DebugM();
		return;
	}

	UViz* ChestViz = NewObject<UViz>(this, ChestVizBP.Get());
	ChestViz->SetSource(this);
	VizRack->AddViz(ChestViz);

	UViz* LegsViz = NewObject<UViz>(this, LegsVizBP.Get());
	LegsViz->SetSource(this);
	VizRack->AddViz(LegsViz);

	UViz* HandsViz = NewObject<UViz>(this, HandsVizBP.Get());
	HandsViz->SetSource(this);
	VizRack->AddViz(HandsViz);

	UViz* FeetViz = NewObject<UViz>(this, FeetVizBP.Get());
	FeetViz->SetSource(this);
	VizRack->AddViz(FeetViz);

}

void UBodyMemHuman::StreamChassis(FDelBasic Callback)
{

	if (ChassisSoft.IsNull())
	{
		LOG.S(SYS).T(TCRIT).W("Chassis is NULL").DebugM();
		return;
	}

	UAppStream::Get()->Stream(ChassisSoft.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &UBodyMemHuman::StreamChassis_Complete, Callback));
}

void UBodyMemHuman::StreamChassis_Complete(FDelBasic Callback)
{
	Callback.Execute();
}

UChassis* UBodyMemHuman::GetChassis()
{
	return NewObject<UChassis>(this, ChassisSoft.Get());
}