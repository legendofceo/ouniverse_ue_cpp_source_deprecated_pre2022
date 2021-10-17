// Fill out your copyright notice in the Description page of Project Settings.


#include "WrapListUi.h"
#include "Components/SizeBox.h"
#include "Components/ScrollBox.h"
#include "Components/WrapBox.h"

void UWrapListUi::NativePreConstruct()
{
	Super::NativePreConstruct();

}

void UWrapListUi::NativeConstruct()
{
	Super::NativeConstruct();
	SizeBoxInnerVar->SetWidthOverride(ElementSizeX * Columns);
	SizeBoxOuterVar->SetHeightOverride(ElementSizeY*Rows);
	WrapBoxVar->WrapSize = ElementSizeX * Columns;
	WrapBoxVar->bExplicitWrapSize = true;
}

UWrapListElement* UWrapListUi::GetSelected()
{
	return VisibleElements[SelectedIndex];
}

void UWrapListUi::AddWidget(UWrapListElement* WidgetToAdd)
{
	WrapBoxVar->AddChildToWrapBox(WidgetToAdd);
	WidgetToAdd->SizeBoxVar->SetWidthOverride(ElementSizeX);
	WidgetToAdd->SizeBoxVar->SetHeightOverride(ElementSizeY);
	VisibleElements.Add(WidgetToAdd);
}


void UWrapListUi::RemoveWidget(UWrapListElement* WidgetToRemove)
{
	WrapBoxVar->RemoveChild(WidgetToRemove);
	VisibleElements.Remove(WidgetToRemove);
}

void UWrapListUi::Update()
{

	if (EmptyElementClass)
	{
		for (UWrapListElement* Element : EmptyElements)
		{
			WrapBoxVar->RemoveChild(Element);
		}

		int TotalShownAtOnce = Columns * Rows;
		int TotalVisibleElements = VisibleElements.Num();

		if (TotalVisibleElements < TotalShownAtOnce)
		{
			int NumToMake = TotalShownAtOnce - TotalVisibleElements;
			UWrapListElement* NewEmpty;

			for (int i = 0; i < NumToMake; i++)
			{
				NewEmpty = CreateWidget<UWrapListElement>(this, EmptyElementClass.Get());
				EmptyElements.Add(NewEmpty);
				WrapBoxVar->AddChildToWrapBox(NewEmpty);
				NewEmpty->SizeBoxVar->SetWidthOverride(ElementSizeX);
				NewEmpty->SizeBoxVar->SetHeightOverride(ElementSizeY);
			}
		}
	}

}

void UWrapListUi::MoveIndex(EWrapListUiDirections Direction)
{

	int CurrentIndex = SelectedIndex;
	int NewIndex = 0;

	switch (Direction) {
	case EWrapListUiDirections::Up:
		NewIndex = SelectedIndex - Columns;
		break;
	case EWrapListUiDirections::Down:
		NewIndex = SelectedIndex + Columns;
		break;
	case EWrapListUiDirections::Left:

		if (CurrentIndex % Columns == 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Left Block!"));
		}
		else
		{
			NewIndex = SelectedIndex - 1;
		}

		break;
	case EWrapListUiDirections::Right:
		
		if ((CurrentIndex+1) % Columns == 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Right Block!"));
		}
		else
		{
			NewIndex = SelectedIndex + 1;
		}

		break;
	}


	if (NewIndex >= 0 && NewIndex < VisibleElements.Num() && NewIndex != CurrentIndex)
	{
		SparkedElement->Unspark();
		SparkedElement = VisibleElements[NewIndex];
		SparkedElement->Spark();
		SelectedIndex = NewIndex;
	}
}

void UWrapListUi::DoSpark()
{
	Spark();
}

void UWrapListUi::Spark()
{
	SparkedElement = VisibleElements[SelectedIndex];
	SparkedElement->Spark();
	BeginSpark();	
}

void UWrapListUi::Unspark()
{
	BeginUnspark();
}



void UWrapListElement::Spark()
{
	BeginSpark();
}

void UWrapListElement::Unspark()
{
	BeginUnspark();
}