// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Object.h"
#include "../type/json.h"
#include "../sys/data_address.h"
#include "../sys/path_address.h"
#include "../sys/form_type.h"

#include "../sys/log.h"
#include "../key/key.h"
#include "../type/map.h"
#include "../type/array.h"
#include "UObject/SoftObjectPtr.h"
#include "form_f.generated.h"

class UAtlas;
class Form_F;
class UFormType;


class DataReport_D
{
public:

	static int const None = 0;
	static int const Approved = 1;
	static int const Noticed = 2;
	static int const Warned = 3;
	static int const Critical = 4;
};


UCLASS(BlueprintType)
class UForm_F : public UObject
{
	GENERATED_BODY()

public:

	UForm_F() {};
	void SetForm(Form_F* InForm);

	UFUNCTION(BlueprintCallable)
	virtual void Save();

	UFUNCTION(BlueprintCallable)
	virtual	void New(UAtlas* InAtlas);

	UFUNCTION(BlueprintCallable)
	void Delete();

	void SetupNew(Form_F* InForm, UAtlas* InAtlas);

	bool IsFormTypeRelative();

	Form_F* Form;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FText ID;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int UID;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	int FormType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAtlas* Atlas;

	UFUNCTION(BlueprintCallable)
	UFormType* GetFormType();

	bool bNew;
};

class Form_F
{

public:

	Form_F() {};
	virtual ~Form_F() {};
	virtual int FormType() { return UFormType::Form; };

	UAtlas* Atlas;
	int32 UID = -1;
	FString ID;

	FString PrintError(FString Key);

	void BaseData(JsonS* J, UAtlas* InAtlas, FLogger* Log);
	
	FString Print();

	JsonS ToJson();

	FString SerializeAsJson() { return ToJson().Serialize(); };

	virtual JsonS* ToJson(JsonS* J);
	virtual int FromJson(JsonS* J, FLogger* Log);

	virtual bool IsRelative(int TypeID);

	virtual UForm_F* ToUObject();

	//template <class Data>
	//void  MakeLink(Data DataPTR, const char* Key, JsonS* J, AAtlas* Atlas);
};