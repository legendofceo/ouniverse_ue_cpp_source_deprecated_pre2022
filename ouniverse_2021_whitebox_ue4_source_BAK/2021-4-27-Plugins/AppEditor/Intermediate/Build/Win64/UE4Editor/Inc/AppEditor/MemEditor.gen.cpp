// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AppEditor/Public/MemEditor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMemEditor() {}
// Cross Module References
	APPEDITOR_API UClass* Z_Construct_UClass_UMemEditor_NoRegister();
	APPEDITOR_API UClass* Z_Construct_UClass_UMemEditor();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_AppEditor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FAssetData();
// End Cross Module References
	DEFINE_FUNCTION(UMemEditor::execBloomMemFlags)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Directory);
		P_GET_STRUCT(FAssetData,Z_Param_AppMemBlueprint);
		P_FINISH;
		P_NATIVE_BEGIN;
		UMemEditor::BloomMemFlags(Z_Param_Directory,Z_Param_AppMemBlueprint);
		P_NATIVE_END;
	}
	void UMemEditor::StaticRegisterNativesUMemEditor()
	{
		UClass* Class = UMemEditor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BloomMemFlags", &UMemEditor::execBloomMemFlags },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMemEditor_BloomMemFlags_Statics
	{
		struct MemEditor_eventBloomMemFlags_Parms
		{
			FString Directory;
			FAssetData AppMemBlueprint;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Directory;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AppMemBlueprint;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMemEditor_BloomMemFlags_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MemEditor_eventBloomMemFlags_Parms, Directory), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMemEditor_BloomMemFlags_Statics::NewProp_AppMemBlueprint = { "AppMemBlueprint", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MemEditor_eventBloomMemFlags_Parms, AppMemBlueprint), Z_Construct_UScriptStruct_FAssetData, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMemEditor_BloomMemFlags_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMemEditor_BloomMemFlags_Statics::NewProp_Directory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMemEditor_BloomMemFlags_Statics::NewProp_AppMemBlueprint,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMemEditor_BloomMemFlags_Statics::Function_MetaDataParams[] = {
		{ "Category", "AppEditorUtilities" },
		{ "ModuleRelativePath", "Public/MemEditor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMemEditor_BloomMemFlags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMemEditor, nullptr, "BloomMemFlags", nullptr, nullptr, sizeof(MemEditor_eventBloomMemFlags_Parms), Z_Construct_UFunction_UMemEditor_BloomMemFlags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMemEditor_BloomMemFlags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMemEditor_BloomMemFlags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMemEditor_BloomMemFlags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMemEditor_BloomMemFlags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMemEditor_BloomMemFlags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMemEditor_NoRegister()
	{
		return UMemEditor::StaticClass();
	}
	struct Z_Construct_UClass_UMemEditor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMemEditor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_AppEditor,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMemEditor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMemEditor_BloomMemFlags, "BloomMemFlags" }, // 4227365614
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMemEditor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MemEditor.h" },
		{ "ModuleRelativePath", "Public/MemEditor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMemEditor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMemEditor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMemEditor_Statics::ClassParams = {
		&UMemEditor::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UMemEditor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMemEditor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMemEditor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMemEditor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMemEditor, 4272301774);
	template<> APPEDITOR_API UClass* StaticClass<UMemEditor>()
	{
		return UMemEditor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMemEditor(Z_Construct_UClass_UMemEditor, &UMemEditor::StaticClass, TEXT("/Script/AppEditor"), TEXT("UMemEditor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMemEditor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
