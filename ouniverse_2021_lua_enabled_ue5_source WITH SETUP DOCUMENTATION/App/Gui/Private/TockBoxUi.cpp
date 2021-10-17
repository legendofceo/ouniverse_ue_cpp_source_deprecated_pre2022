// Fill out your copyright notice in the Description page of Project Settings.


#include "TockBoxUi.h"
#include "Components/HorizontalBox.h"
#include "Components/SizeBox.h"

void UTockBoxHorizontalUi::Build()
{

}

void UTockBoxHorizontalUi::ShiftLeft()
{
	bShiftReverse = true;


	Box->ClearChildren();
	int ChildrenNum = Elements.Num();

	for (int i = 0; i < SideUnits; i++)
	{
		if (Index - i >= 0)
		{
			Box->AddChild(Elements[Index - i]);
		}
		else
		{
			// Widget creation
			USizeBox* SizeBox = NewObject<USizeBox>(this, USizeBox::StaticClass());

			// Adding widget to canvas panel
			SizeBox->SetWidthOverride(ElementSize);
			Box->AddChild(SizeBox);
		}
	}

	Box->AddChild(Elements[Index]);

	for (int i = 0; i < SideUnits; i++)
	{
		int SideIndex = Index + 1;
		if (SideIndex + i < ChildrenNum)
		{
			Box->AddChild(Elements[SideIndex]);
		}
		else
		{
			USizeBox* SizeBox = NewObject<USizeBox>(this, USizeBox::StaticClass());
			SizeBox->SetWidthOverride(ElementSize);
			Box->AddChild(SizeBox);
		}
	}


	BeginShift();
}

void UTockBoxHorizontalUi::AddElement(UTockBoxElementUi* Element)
{
	Elements.Add(Element);
}

void UTockBoxHorizontalUi::ShiftRight()
{
	bShiftReverse = false;

	BeginShift();
}

void UTockBoxHorizontalUi::BeginShift()
{
	ShiftDelta = 0.0;
	bShifting = true;

	Shift(0.0);
	TickDelegate = FTickerDelegate::CreateUObject(this, &UTockBoxHorizontalUi::Shift);
	TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(TickDelegate);
}

bool UTockBoxHorizontalUi::Shift(float Delta)
{
	ShiftDelta += Delta;
	ActiveSlots.Reset();

	int ChildrenNum = Elements.Num();
	/**
	int Max = (ChildrenNum % 2 == 0) ?  ChildrenNum : ChildrenNum-1;

	if (ChildrenNum < MaxElements)
	{

	}
	if (1 == 1)
	{
		float Alpha = ShiftDelta / ShiftTime;

		//(a * (1.0 - f)) + (b * f);
		float Translate = ElementSize * Alpha;


	}
	else
	{
		bShifting = false;
		FTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);
	}
	*/
	return false;
}
