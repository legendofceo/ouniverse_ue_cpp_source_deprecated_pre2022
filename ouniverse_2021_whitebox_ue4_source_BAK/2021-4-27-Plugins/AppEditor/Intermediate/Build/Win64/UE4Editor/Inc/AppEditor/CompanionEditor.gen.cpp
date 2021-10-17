// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AppEditor/Public/CompanionEditor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCompanionEditor() {}
// Cross Module References
	APPEDITOR_API UClass* Z_Construct_UClass_UCompanionEditor_NoRegister();
	APPEDITOR_API UClass* Z_Construct_UClass_UCompanionEditor();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_AppEditor();
	ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
	APPEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FLogPP();
// End Cross Module References
	DEFINE_FUNCTION(UCompanionEditor::execProcessCompanionData)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Directory);
		P_GET_OBJECT(UDataTable,Z_Param_DataTable);
		P_GET_STRUCT_REF(FLogPP,Z_Param_Out_Log);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_DirNum);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_TableNum);
		P_FINISH;
		P_NATIVE_BEGIN;
		UCompanionEditor::ProcessCompanionData(Z_Param_Directory,Z_Param_DataTable,Z_Param_Out_Log,Z_Param_Out_DirNum,Z_Param_Out_TableNum);
		P_NATIVE_END;
	}
	void UCompanionEditor::StaticRegisterNativesUCompanionEditor()
	{
		UClass* Class = UCompanionEditor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ProcessCompanionData", &UCompanionEditor::execProcessCompanionData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics
	{
		struct CompanionEditor_eventProcessCompanionData_Parms
		{
			FString Directory;
			UDataTable* DataTable;
			FLogPP Log;
			int32 DirNum;
			int32 TableNum;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Directory;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DataTable;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Log;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_DirNum;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_TableNum;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompanionEditor_eventProcessCompanionData_Parms, Directory), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::NewProp_DataTable = { "DataTable", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompanionEditor_eventProcessCompanionData_Parms, DataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::NewProp_Log = { "Log", nullptr, (EPropertyFlags)0x0010000008000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompanionEditor_eventProcessCompanionData_Parms, Log), Z_Construct_UScriptStruct_FLogPP, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::NewProp_DirNum = { "DirNum", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompanionEditor_eventProcessCompanionData_Parms, DirNum), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::NewProp_TableNum = { "TableNum", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CompanionEditor_eventProcessCompanionData_Parms, TableNum), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::NewProp_Directory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::NewProp_DataTable,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::NewProp_Log,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::NewProp_DirNum,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::NewProp_TableNum,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::Function_MetaDataParams[] = {
		{ "Category", "AppEditorUtilities" },
		{ "ModuleRelativePath", "Public/CompanionEditor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCompanionEditor, nullptr, "ProcessCompanionData", nullptr, nullptr, sizeof(CompanionEditor_eventProcessCompanionData_Parms), Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCompanionEditor_NoRegister()
	{
		return UCompanionEditor::StaticClass();
	}
	struct Z_Construct_UClass_UCompanionEditor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCompanionEditor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_AppEditor,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCompanionEditor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCompanionEditor_ProcessCompanionData, "ProcessCompanionData" }, // 2728351086
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCompanionEditor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CompanionEditor.h" },
		{ "ModuleRelativePath", "Public/CompanionEditor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCompanionEditor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCompanionEditor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCompanionEditor_Statics::ClassParams = {
		&UCompanionEditor::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCompanionEditor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCompanionEditor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCompanionEditor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCompanionEditor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCompanionEditor, 2721139339);
	template<> APPEDITOR_API UClass* StaticClass<UCompanionEditor>()
	{
		return UCompanionEditor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCompanionEditor(Z_Construct_UClass_UCompanionEditor, &UCompanionEditor::StaticClass, TEXT("/Script/AppEditor"), TEXT("UCompanionEditor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCompanionEditor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
