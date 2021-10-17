// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AppEditor/Public/Preprocessor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePreprocessor() {}
// Cross Module References
	APPEDITOR_API UClass* Z_Construct_UClass_UPreprocessor_NoRegister();
	APPEDITOR_API UClass* Z_Construct_UClass_UPreprocessor();
	BLUTILITY_API UClass* Z_Construct_UClass_UEditorUtilityWidget();
	UPackage* Z_Construct_UPackage__Script_AppEditor();
	APP_API UClass* Z_Construct_UClass_UGameData_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
	APPEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FLogPP();
// End Cross Module References
	DEFINE_FUNCTION(UPreprocessor::execProcessEquipmentSlots)
	{
		P_GET_SOFTCLASS(TSoftClassPtr<UGameData> ,Z_Param_GameDataBP);
		P_GET_OBJECT(UDataTable,Z_Param_DataTable);
		P_GET_STRUCT_REF(FLogPP,Z_Param_Out_Log);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_EquipmentSlotsNum);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPreprocessor::ProcessEquipmentSlots(Z_Param_GameDataBP,Z_Param_DataTable,Z_Param_Out_Log,Z_Param_Out_EquipmentSlotsNum);
		P_NATIVE_END;
	}
	void UPreprocessor::StaticRegisterNativesUPreprocessor()
	{
		UClass* Class = UPreprocessor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ProcessEquipmentSlots", &UPreprocessor::execProcessEquipmentSlots },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics
	{
		struct Preprocessor_eventProcessEquipmentSlots_Parms
		{
			TSoftClassPtr<UGameData>  GameDataBP;
			UDataTable* DataTable;
			FLogPP Log;
			int32 EquipmentSlotsNum;
		};
		static const UE4CodeGen_Private::FSoftClassPropertyParams NewProp_GameDataBP;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DataTable;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Log;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_EquipmentSlotsNum;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FSoftClassPropertyParams Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::NewProp_GameDataBP = { "GameDataBP", nullptr, (EPropertyFlags)0x0014000000000080, UE4CodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Preprocessor_eventProcessEquipmentSlots_Parms, GameDataBP), Z_Construct_UClass_UGameData_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::NewProp_DataTable = { "DataTable", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Preprocessor_eventProcessEquipmentSlots_Parms, DataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::NewProp_Log = { "Log", nullptr, (EPropertyFlags)0x0010000008000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Preprocessor_eventProcessEquipmentSlots_Parms, Log), Z_Construct_UScriptStruct_FLogPP, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::NewProp_EquipmentSlotsNum = { "EquipmentSlotsNum", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Preprocessor_eventProcessEquipmentSlots_Parms, EquipmentSlotsNum), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::NewProp_GameDataBP,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::NewProp_DataTable,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::NewProp_Log,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::NewProp_EquipmentSlotsNum,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::Function_MetaDataParams[] = {
		{ "Category", "AppEditorUtilities" },
		{ "ModuleRelativePath", "Public/Preprocessor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPreprocessor, nullptr, "ProcessEquipmentSlots", nullptr, nullptr, sizeof(Preprocessor_eventProcessEquipmentSlots_Parms), Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPreprocessor_NoRegister()
	{
		return UPreprocessor::StaticClass();
	}
	struct Z_Construct_UClass_UPreprocessor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPreprocessor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEditorUtilityWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_AppEditor,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPreprocessor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPreprocessor_ProcessEquipmentSlots, "ProcessEquipmentSlots" }, // 2302395042
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPreprocessor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Preprocessor.h" },
		{ "ModuleRelativePath", "Public/Preprocessor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPreprocessor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPreprocessor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPreprocessor_Statics::ClassParams = {
		&UPreprocessor::StaticClass,
		"Editor",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B010A4u,
		METADATA_PARAMS(Z_Construct_UClass_UPreprocessor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPreprocessor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPreprocessor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPreprocessor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPreprocessor, 2103980108);
	template<> APPEDITOR_API UClass* StaticClass<UPreprocessor>()
	{
		return UPreprocessor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPreprocessor(Z_Construct_UClass_UPreprocessor, &UPreprocessor::StaticClass, TEXT("/Script/AppEditor"), TEXT("UPreprocessor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPreprocessor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
