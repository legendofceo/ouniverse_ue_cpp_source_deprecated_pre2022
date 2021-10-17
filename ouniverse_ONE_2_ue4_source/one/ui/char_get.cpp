// Copyright Epic Games, Inc. All Rights Reserved.


#include "char_get.h"

void UCharGet_U::NativeConstruct()
{
	bIsFocusable = true;
	Super::NativeConstruct();
}

FReply UCharGet_U::NativeOnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharEvent)
{

	TCHAR Char = InCharEvent.GetCharacter();
	FString CharText = FString(1,&Char);
	OnCharGet.Broadcast(CharText,false);
	return FReply::Handled();
}