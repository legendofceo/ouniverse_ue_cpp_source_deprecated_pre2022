// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Object.h"
#include "../../type/json.h"
#include "../form_f.h"
#include "../../sys/atlas.h"
#include "form_link.generated.h"

class UAtlas;
class UForm_F;

#define FORMLINK_NULL 0


USTRUCT(BlueprintType)
struct FFormLink
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UForm_F* Form;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bSoftLink;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEmpty;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int AtlasUID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FormUID;
};


UCLASS(BlueprintType)
class UFormLinkStatics : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static void UpdateFormLink(FFormLink S)
	{
		S.Form->ID = FText::FromString(S.Form->Form->ID);

	}
};

template <typename D>
struct FormLinkS
{

	FormLinkS()
	{
		Data_ = nullptr;
	}


	FDataAddress DataAddress;
	D Data_;


	bool IsEmpty()
	{
		if (DataAddress.IsNull())
		{
			return true;
		}
		return false;
	}

	bool IsSoftLink()
	{
		if (Data_ == nullptr)
		{
			return true;
		}
		return false;
	}


	FFormLink CreateStruct()
	{
		FFormLink S = FFormLink();
		
		if (IsEmpty())
		{
			S.bEmpty = true;
		}
		else if(IsSoftLink())
		{
			S.bSoftLink = true;
		}
		else
		{
			S.Form = Data_->ToUObject();
			S.AtlasUID = DataAddress.PackUN;
			S.FormUID = DataAddress.DataUN;
		}

		return S;
	}

	void FromStruct(FFormLink S)
	{

		if (S.bEmpty)
		{
			DataAddress.Null();
		}
		else if(S.bSoftLink)
		{
			DataAddress = FDataAddress(S.AtlasUID, S.FormUID);
		}
		else
		{
			DataAddress.SetPack(S.Form->Atlas->UID);
			DataAddress.SetForm(S.Form->UID);
			Data_ = static_cast<D>(S.Form->Form);
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, Data_->ID);
		}
	}

	bool FromJson(Form_F* InData, JsonS* J, const char* Key, bool bNullAllowed=false)
	{
		JsonS JV;
		Form_F* Output;

		if (!J->Try(JV, Key))
		{
			return false;
		}


		int OutUN;
		if (JV.TryInt(OutUN))
		{
			if (OutUN == FORMLINK_NULL)
			{
				if (bNullAllowed)
				{
					return false;
				}
				else
				{
					return true;
				}
			}

			//If only a number is provided then the data address is within the containing datapack.
			DataAddress.SetPack(InData->Atlas->UID);
			DataAddress.SetForm(OutUN);

			if (InData->Atlas->TryData(Output, OutUN))
			{
				Data_ = static_cast<D>(Output);
				return true;
			}

			DataAddress.Null();
			return false;

		}


		else if (JV.IsArray())
		{
			//If an array is present the data address is within an external datapack.

			if (JV.At(0).TryInt(OutUN))
			{
				DataAddress.SetPack(OutUN);
			}

			if (JV.At(1).TryInt(OutUN))
			{
				DataAddress.SetForm(OutUN);
			}

			UAtlas* OutAtlas = nullptr;

			if (UAtlas::TryAtlas(OutAtlas, OutUN))
			{
				if (OutAtlas->TryData(Output, OutUN))
				{
					Data_ = static_cast<D>(Output);
					return true;
				}
			}

		}

		return false;
	}

	JsonS ToJson(Form_F* InData)
	{
		if(DataAddress.IsEmpty())
		{
			return JsonS(FString(FORMLINK_NULL));
		}
		else
		{
			if (DataAddress.Pack() == InData->Atlas->UID)
			{
				return JsonS(DataAddress.Form());
			}
			else
			{
				ArrayC<JsonS> JsonArr;
				JsonArr.Add(JsonS(DataAddress.Pack()));
				JsonArr.Add(JsonS(DataAddress.Form()));
				return JsonS(JsonArr);

			}
		}
	}
};