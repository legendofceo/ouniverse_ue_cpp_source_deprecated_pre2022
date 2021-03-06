//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPtr.h"
#include "ClassProtocol.generated.h"

class USymPro;
class UWriPro;
class UCnsTray;
class UCnsShelf;
class UWriFile_ScrollEntry;
class UWriData_ScrollEntry;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UClassProtocol : public UObject
{

	GENERATED_BODY()

public:

	static void Initialize();

	static UClassProtocol* Get();

	UPROPERTY(EditAnywhere, meta = (Category = "System"))
	TSubclassOf<USymPro>			SymProUI;

	UPROPERTY(EditAnywhere, meta = (Category = "System"))
	TSubclassOf<UWriPro>			WriProUI;

	UPROPERTY(EditAnywhere, meta = (Category = "System"))
	TSubclassOf<UWriFile_ScrollEntry>	WriLoadout_ScrollEntryUI;
	
	UPROPERTY(EditAnywhere, meta = (Category = "System"))
	TSubclassOf<UWriData_ScrollEntry>		WriForm_ScrollEntryUI;

	UPROPERTY(EditAnywhere, meta = (Category = "System"))
	TSubclassOf<UCnsShelf>			CnsShelfUI;

	UPROPERTY(EditAnywhere, meta = (Category = "System"))
	TSubclassOf<UCnsTray>			CnsTrayUI;


};