// Fill out your copyright notice in the Description page of Project Settings.


#include "Keynet.h"
#include "Input.h"

UKeynet* UKeynet::Create()
{
	UKeynet* NewKeymapLib = NewObject<UKeynet>();
	return NewKeymapLib;
}

void UKeynet::AddKeymap(FKeymap Keymap)
{
	Keymaps.Add(Keymap);
	bNeedsRebuilding = true;
};

void UKeynet::Rebuild()
{
	uint8 i = 0;
	int L = Keymaps.Num();

	KeymapRefs.Clear();

	for (i = 0; i < L; i++)
	{
		FKeymap* CurKeymap = &Keymaps[i];

		if (CurKeymap->Primary != NULL)
		{
			KeymapRefs.Add(CurKeymap->Primary->InputCode, CurKeymap);
		}		
		if (CurKeymap->Secondary != NULL)
		{
			KeymapRefs.Add(CurKeymap->Secondary->InputCode, CurKeymap);
		}
		if (CurKeymap->Pad != NULL)
		{
			KeymapRefs.Add(CurKeymap->Pad->InputCode, CurKeymap);
		}
	}

	bNeedsRebuilding = false;
}

bool UKeynet::TryBind(uint8& Output, uint8 InputBTCode)
{
	if (KeymapRefs.Contains(InputBTCode))
	{
		Output = KeymapRefs.Find(InputBTCode)->Byte;
		return true;
	}
	else
	{
		return false;
	}
}