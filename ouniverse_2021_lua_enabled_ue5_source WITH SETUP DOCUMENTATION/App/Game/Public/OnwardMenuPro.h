// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Protocol.h"
#include "BaseUi.h"
#include "Index.h"
#include "Delegate.h"
#include "OnwardMenuPro.generated.h"



class UOnwardMenuTopHeaderUi;
class UOnwardMenuCompanionsSub;
class UOnwardMenuOverviewSub;


UENUM(Blueprintable)
enum class EUOnwardMenuState : uint8
{
	None			UMETA(DisplayName = "None"),
	Overview		UMETA(DisplayName = "Overview"),
	Companions		UMETA(DisplayName = "Companions"),
};

UENUM(Blueprintable)
enum class EOnwardMenuSubmenus : uint8
{
	Overview		UMETA(DisplayName = "Overview"),
	Companions		UMETA(DisplayName = "Companions"),
	MAX				UMETA(DisplayName = "MAX"),
};

UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UOnwardMenuPro : public UProtocol
{
	GENERATED_BODY()

	static const FName SYS;

public:

	/** Initialization*/

	UOnwardMenuPro();

	static UOnwardMenuPro* Get();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(DisplayName=":OnwardMenuPro"))
	static void GetBP(UOnwardMenuPro*& OnwardMenuPro);

	void Init() override;

	void Engage();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "#Engage"))
	void EngageBP();
};






UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UOnwardMenuHeader : public UBaseUi
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="#UpdateSelection"))
	int UpdateSelection(int NewSelection);

};



UCLASS(Abstract, BlueprintType, Blueprintable)
class APP_API UOnwardMenuSubmenu : public UBaseUi
{
	GENERATED_BODY()

public:




	void Init(UOnwardMenuPro* InPro, UOnwardMenuSubmenu* InParent);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UOnwardMenuPro* Pro = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UOnwardMenuSubmenu* Parent = nullptr;
};