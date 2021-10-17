// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Type/Map.h"
#include "Keynet.generated.h"

/**
 * 
 */

class UInputButton;


USTRUCT()
struct FKeymap
{
	GENERATED_BODY()


	UPROPERTY(VisibleAnywhere)
	uint8 Byte;
	
	UPROPERTY(VisibleAnywhere)
	UInputButton* Primary = NULL;

	UPROPERTY(VisibleAnywhere)
	UInputButton* Secondary = NULL;

	UPROPERTY(VisibleAnywhere)
	UInputButton* Pad = NULL;


	FKeymap()
	{
		
	}

	FKeymap(uint8 InByte)
	{
		Byte = InByte;
	}

	FKeymap(uint8 InByte, UInputButton* PrimaryBT)
	{
		Byte = InByte;
		Primary = PrimaryBT;
	}
};


UCLASS()
class APP_API UKeynet : public UObject
{
	GENERATED_BODY()

public:

	static UKeynet* Create();

	UPROPERTY(VisibleAnywhere)
	bool bNeedsRebuilding;

	UPROPERTY(VisibleAnywhere)
	TArray<FKeymap> Keymaps;

	MapC<uint8, FKeymap*> KeymapRefs;

	void AddKeymap(FKeymap Keymap);

	void Rebuild();

	bool TryBind(uint8& Output, uint8 InputBTCode);

};