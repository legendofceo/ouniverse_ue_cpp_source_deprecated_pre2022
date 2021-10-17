// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AppEditor/Public/LogPP.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLogPP() {}
// Cross Module References
	APPEDITOR_API UEnum* Z_Construct_UEnum_AppEditor_LogVerbPP();
	UPackage* Z_Construct_UPackage__Script_AppEditor();
	APPEDITOR_API UEnum* Z_Construct_UEnum_AppEditor_LogTypePP();
	APPEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FLogPP();
	APPEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FLogEntryPP();
// End Cross Module References
	static UEnum* LogVerbPP_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_AppEditor_LogVerbPP, Z_Construct_UPackage__Script_AppEditor(), TEXT("LogVerbPP"));
		}
		return Singleton;
	}
	template<> APPEDITOR_API UEnum* StaticEnum<LogVerbPP>()
	{
		return LogVerbPP_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_LogVerbPP(LogVerbPP_StaticEnum, TEXT("/Script/AppEditor"), TEXT("LogVerbPP"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_AppEditor_LogVerbPP_Hash() { return 1344404429U; }
	UEnum* Z_Construct_UEnum_AppEditor_LogVerbPP()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_AppEditor();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("LogVerbPP"), 0, Get_Z_Construct_UEnum_AppEditor_LogVerbPP_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "LogVerbPP::None", (int64)LogVerbPP::None },
				{ "LogVerbPP::Light", (int64)LogVerbPP::Light },
				{ "LogVerbPP::Medium", (int64)LogVerbPP::Medium },
				{ "LogVerbPP::Heavy", (int64)LogVerbPP::Heavy },
				{ "LogVerbPP::Massive", (int64)LogVerbPP::Massive },
				{ "LogVerbPP::OMFG", (int64)LogVerbPP::OMFG },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Heavy.DisplayName", "Heavy" },
				{ "Heavy.Name", "LogVerbPP::Heavy" },
				{ "Light.DisplayName", "Light" },
				{ "Light.Name", "LogVerbPP::Light" },
				{ "Massive.DisplayName", "Massive" },
				{ "Massive.Name", "LogVerbPP::Massive" },
				{ "Medium.DisplayName", "Medium" },
				{ "Medium.Name", "LogVerbPP::Medium" },
				{ "ModuleRelativePath", "Public/LogPP.h" },
				{ "None.DisplayName", "None" },
				{ "None.Name", "LogVerbPP::None" },
				{ "OMFG.DisplayName", "OMFG" },
				{ "OMFG.Name", "LogVerbPP::OMFG" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_AppEditor,
				nullptr,
				"LogVerbPP",
				"LogVerbPP",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* LogTypePP_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_AppEditor_LogTypePP, Z_Construct_UPackage__Script_AppEditor(), TEXT("LogTypePP"));
		}
		return Singleton;
	}
	template<> APPEDITOR_API UEnum* StaticEnum<LogTypePP>()
	{
		return LogTypePP_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_LogTypePP(LogTypePP_StaticEnum, TEXT("/Script/AppEditor"), TEXT("LogTypePP"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_AppEditor_LogTypePP_Hash() { return 1344965885U; }
	UEnum* Z_Construct_UEnum_AppEditor_LogTypePP()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_AppEditor();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("LogTypePP"), 0, Get_Z_Construct_UEnum_AppEditor_LogTypePP_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "LogTypePP::Normal", (int64)LogTypePP::Normal },
				{ "LogTypePP::Warning", (int64)LogTypePP::Warning },
				{ "LogTypePP::Critical", (int64)LogTypePP::Critical },
				{ "LogTypePP::Header", (int64)LogTypePP::Header },
				{ "LogTypePP::Note", (int64)LogTypePP::Note },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Critical.DisplayName", "Critical" },
				{ "Critical.Name", "LogTypePP::Critical" },
				{ "Header.DisplayName", "Header" },
				{ "Header.Name", "LogTypePP::Header" },
				{ "ModuleRelativePath", "Public/LogPP.h" },
				{ "Normal.DisplayName", "Normal" },
				{ "Normal.Name", "LogTypePP::Normal" },
				{ "Note.DisplayName", "Note" },
				{ "Note.Name", "LogTypePP::Note" },
				{ "Warning.DisplayName", "Warning" },
				{ "Warning.Name", "LogTypePP::Warning" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_AppEditor,
				nullptr,
				"LogTypePP",
				"LogTypePP",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FLogPP::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern APPEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FLogPP_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FLogPP, Z_Construct_UPackage__Script_AppEditor(), TEXT("LogPP"), sizeof(FLogPP), Get_Z_Construct_UScriptStruct_FLogPP_Hash());
	}
	return Singleton;
}
template<> APPEDITOR_API UScriptStruct* StaticStruct<FLogPP>()
{
	return FLogPP::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FLogPP(FLogPP::StaticStruct, TEXT("/Script/AppEditor"), TEXT("LogPP"), false, nullptr, nullptr);
static struct FScriptStruct_AppEditor_StaticRegisterNativesFLogPP
{
	FScriptStruct_AppEditor_StaticRegisterNativesFLogPP()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("LogPP")),new UScriptStruct::TCppStructOps<FLogPP>);
	}
} ScriptStruct_AppEditor_StaticRegisterNativesFLogPP;
	struct Z_Construct_UScriptStruct_FLogPP_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Entries_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Entries_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Entries;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLogPP_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/LogPP.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FLogPP_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLogPP>();
	}
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLogPP_Statics::NewProp_Entries_Inner = { "Entries", nullptr, (EPropertyFlags)0x0000000000020000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FLogEntryPP, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLogPP_Statics::NewProp_Entries_MetaData[] = {
		{ "Category", "LogPP" },
		{ "ModuleRelativePath", "Public/LogPP.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FLogPP_Statics::NewProp_Entries = { "Entries", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FLogPP, Entries), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FLogPP_Statics::NewProp_Entries_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLogPP_Statics::NewProp_Entries_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLogPP_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLogPP_Statics::NewProp_Entries_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLogPP_Statics::NewProp_Entries,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLogPP_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_AppEditor,
		nullptr,
		&NewStructOps,
		"LogPP",
		sizeof(FLogPP),
		alignof(FLogPP),
		Z_Construct_UScriptStruct_FLogPP_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLogPP_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FLogPP_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLogPP_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FLogPP()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FLogPP_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_AppEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("LogPP"), sizeof(FLogPP), Get_Z_Construct_UScriptStruct_FLogPP_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FLogPP_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FLogPP_Hash() { return 761886666U; }
class UScriptStruct* FLogEntryPP::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern APPEDITOR_API uint32 Get_Z_Construct_UScriptStruct_FLogEntryPP_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FLogEntryPP, Z_Construct_UPackage__Script_AppEditor(), TEXT("LogEntryPP"), sizeof(FLogEntryPP), Get_Z_Construct_UScriptStruct_FLogEntryPP_Hash());
	}
	return Singleton;
}
template<> APPEDITOR_API UScriptStruct* StaticStruct<FLogEntryPP>()
{
	return FLogEntryPP::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FLogEntryPP(FLogEntryPP::StaticStruct, TEXT("/Script/AppEditor"), TEXT("LogEntryPP"), false, nullptr, nullptr);
static struct FScriptStruct_AppEditor_StaticRegisterNativesFLogEntryPP
{
	FScriptStruct_AppEditor_StaticRegisterNativesFLogEntryPP()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("LogEntryPP")),new UScriptStruct::TCppStructOps<FLogEntryPP>);
	}
} ScriptStruct_AppEditor_StaticRegisterNativesFLogEntryPP;
	struct Z_Construct_UScriptStruct_FLogEntryPP_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_System_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_System;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ID_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_ID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Text;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Indent_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Indent;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_LogType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LogType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_LogType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Verbosity_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Verbosity_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Verbosity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DataList_MetaData[];
#endif
		static void NewProp_DataList_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_DataList;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Time_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Time;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLogEntryPP_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/LogPP.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLogEntryPP>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_System_MetaData[] = {
		{ "Category", "LogEntryPP" },
		{ "ModuleRelativePath", "Public/LogPP.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_System = { "System", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FLogEntryPP, System), METADATA_PARAMS(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_System_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_System_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_ID_MetaData[] = {
		{ "Category", "LogEntryPP" },
		{ "ModuleRelativePath", "Public/LogPP.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FLogEntryPP, ID), METADATA_PARAMS(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_ID_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_ID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Text_MetaData[] = {
		{ "Category", "LogEntryPP" },
		{ "ModuleRelativePath", "Public/LogPP.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FLogEntryPP, Text), METADATA_PARAMS(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Text_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Text_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Indent_MetaData[] = {
		{ "Category", "LogEntryPP" },
		{ "ModuleRelativePath", "Public/LogPP.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Indent = { "Indent", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FLogEntryPP, Indent), nullptr, METADATA_PARAMS(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Indent_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Indent_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_LogType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_LogType_MetaData[] = {
		{ "Category", "LogEntryPP" },
		{ "ModuleRelativePath", "Public/LogPP.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_LogType = { "LogType", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FLogEntryPP, LogType), Z_Construct_UEnum_AppEditor_LogTypePP, METADATA_PARAMS(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_LogType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_LogType_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Verbosity_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Verbosity_MetaData[] = {
		{ "Category", "LogEntryPP" },
		{ "ModuleRelativePath", "Public/LogPP.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Verbosity = { "Verbosity", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FLogEntryPP, Verbosity), Z_Construct_UEnum_AppEditor_LogVerbPP, METADATA_PARAMS(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Verbosity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Verbosity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_DataList_MetaData[] = {
		{ "Category", "LogEntryPP" },
		{ "ModuleRelativePath", "Public/LogPP.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_DataList_SetBit(void* Obj)
	{
		((FLogEntryPP*)Obj)->DataList = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_DataList = { "DataList", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FLogEntryPP), &Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_DataList_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_DataList_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_DataList_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Time_MetaData[] = {
		{ "Category", "LogEntryPP" },
		{ "ModuleRelativePath", "Public/LogPP.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FLogEntryPP, Time), METADATA_PARAMS(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Time_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Time_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLogEntryPP_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_System,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_ID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Text,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Indent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_LogType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_LogType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Verbosity_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Verbosity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_DataList,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLogEntryPP_Statics::NewProp_Time,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLogEntryPP_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_AppEditor,
		nullptr,
		&NewStructOps,
		"LogEntryPP",
		sizeof(FLogEntryPP),
		alignof(FLogEntryPP),
		Z_Construct_UScriptStruct_FLogEntryPP_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLogEntryPP_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FLogEntryPP_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLogEntryPP_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FLogEntryPP()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FLogEntryPP_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_AppEditor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("LogEntryPP"), sizeof(FLogEntryPP), Get_Z_Construct_UScriptStruct_FLogEntryPP_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FLogEntryPP_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FLogEntryPP_Hash() { return 2924458111U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
