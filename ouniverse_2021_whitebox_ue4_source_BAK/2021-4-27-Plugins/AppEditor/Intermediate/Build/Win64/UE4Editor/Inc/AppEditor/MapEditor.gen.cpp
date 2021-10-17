// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AppEditor/Public/MapEditor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMapEditor() {}
// Cross Module References
	APPEDITOR_API UClass* Z_Construct_UClass_UMapEditor_NoRegister();
	APPEDITOR_API UClass* Z_Construct_UClass_UMapEditor();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_AppEditor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FAssetData();
// End Cross Module References
	DEFINE_FUNCTION(UMapEditor::execBloomMapData)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Directory);
		P_GET_STRUCT(FAssetData,Z_Param_AppMemBlueprint);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_MapsAdded);
		P_FINISH;
		P_NATIVE_BEGIN;
		UMapEditor::BloomMapData(Z_Param_Directory,Z_Param_AppMemBlueprint,Z_Param_Out_MapsAdded);
		P_NATIVE_END;
	}
	void UMapEditor::StaticRegisterNativesUMapEditor()
	{
		UClass* Class = UMapEditor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BloomMapData", &UMapEditor::execBloomMapData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMapEditor_BloomMapData_Statics
	{
		struct MapEditor_eventBloomMapData_Parms
		{
			FString Directory;
			FAssetData AppMemBlueprint;
			int32 MapsAdded;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Directory;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AppMemBlueprint;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MapsAdded;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMapEditor_BloomMapData_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MapEditor_eventBloomMapData_Parms, Directory), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMapEditor_BloomMapData_Statics::NewProp_AppMemBlueprint = { "AppMemBlueprint", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MapEditor_eventBloomMapData_Parms, AppMemBlueprint), Z_Construct_UScriptStruct_FAssetData, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UMapEditor_BloomMapData_Statics::NewProp_MapsAdded = { "MapsAdded", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MapEditor_eventBloomMapData_Parms, MapsAdded), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMapEditor_BloomMapData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMapEditor_BloomMapData_Statics::NewProp_Directory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMapEditor_BloomMapData_Statics::NewProp_AppMemBlueprint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMapEditor_BloomMapData_Statics::NewProp_MapsAdded,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMapEditor_BloomMapData_Statics::Function_MetaDataParams[] = {
		{ "Category", "AppEditorUtilities" },
		{ "ModuleRelativePath", "Public/MapEditor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMapEditor_BloomMapData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMapEditor, nullptr, "BloomMapData", nullptr, nullptr, sizeof(MapEditor_eventBloomMapData_Parms), Z_Construct_UFunction_UMapEditor_BloomMapData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMapEditor_BloomMapData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMapEditor_BloomMapData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMapEditor_BloomMapData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMapEditor_BloomMapData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMapEditor_BloomMapData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMapEditor_NoRegister()
	{
		return UMapEditor::StaticClass();
	}
	struct Z_Construct_UClass_UMapEditor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMapEditor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_AppEditor,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMapEditor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMapEditor_BloomMapData, "BloomMapData" }, // 1137285820
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMapEditor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MapEditor.h" },
		{ "ModuleRelativePath", "Public/MapEditor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMapEditor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMapEditor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMapEditor_Statics::ClassParams = {
		&UMapEditor::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UMapEditor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMapEditor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMapEditor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMapEditor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMapEditor, 1133962973);
	template<> APPEDITOR_API UClass* StaticClass<UMapEditor>()
	{
		return UMapEditor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMapEditor(Z_Construct_UClass_UMapEditor, &UMapEditor::StaticClass, TEXT("/Script/AppEditor"), TEXT("UMapEditor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMapEditor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
