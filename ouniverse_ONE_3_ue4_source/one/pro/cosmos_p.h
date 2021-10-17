// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "protocol_p.h"
#include "../sys/log.h"
#include "Engine/LevelStreamingDynamic.h"
#include "cosmos_p.generated.h"


class UViewportUE;
class AControlUE;
class AModeUE;
class AHudUE;

class AFileManager;
class UTranslationManager;
class AUserManager;
class AMemoryManager;
class ADeepMemory;
class UIcoManager;
class ALogManager;


UENUM(BlueprintType)
enum class EBootCMD : uint8
{
	Official 	UMETA(DisplayName = "Official"),
	LevelDev	UMETA(DisplayName = "LevelDev"),
	UiIso		UMETA(DisplayName = "UiIso"),
	Scribe		UMETA(DisplayName = "Scribe"),
	Blank		UMETA(DisplayName = "Blank")
};

UCLASS()
class ACosmos_P : public AProtocol_P
{

	GENERATED_BODY()

public:

	ACosmos_P();

	UFUNCTION(BlueprintCallable, Category = "Cosmos", meta = (WorldContext = "WorldCTX", ShowWorldContextPin))
	void BigBang(TEnumAsByte<EBootCMD> InBootCommand, 
		TSoftClassPtr<UIcoManager> IcoManagerClass,
		UObject* WorldCTX, bool bSkipIntros, FString AutoUserID, FString AutoLoadout);

	UFUNCTION(BlueprintCallable, Category = "Cosmos") 
	static ACosmos_P* GetCosmos();

	static ACosmos_P* Get();

	UPROPERTY(VisibleAnywhere, meta = (category = "0-Details"))
	TEnumAsByte<EBootCMD> BootCommand;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "0-Details")
	FString PlatformName;

	UPROPERTY(VisibleAnywhere, meta = (category = "0-Details"))
	FLogger Log;


	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	bool bPreDataLoaded;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	UViewportUE* Viewport;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	AControlUE* Control;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	AModeUE* Mode;
	
	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	AHudUE* Hud;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	AFileManager* FileManager;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	AUserManager* UserManager;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	UTranslationManager* TranslationManager;


	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	AMemoryManager* MemoryManager;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	UIcoManager* IcoManager;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	ADeepMemory* DeepMemory;

	UPROPERTY(Category = "0 Details", VisibleAnywhere, BlueprintReadOnly)
	ALogManager* LogManager;

	UFUNCTION(Category = "0 Details", BlueprintCallable)
	static void LoadPreData();


	UFUNCTION(Category = "0 Details", BlueprintCallable)
	static void PreDataStatus(bool& DataLoaded, bool& HasActiveUser, bool& HasAnyUser);


};