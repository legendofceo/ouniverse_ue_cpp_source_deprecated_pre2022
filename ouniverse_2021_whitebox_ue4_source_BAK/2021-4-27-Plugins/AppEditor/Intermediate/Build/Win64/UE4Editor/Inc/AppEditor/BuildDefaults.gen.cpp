// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AppEditor/Public/BuildDefaults.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBuildDefaults() {}
// Cross Module References
	APPEDITOR_API UClass* Z_Construct_UClass_UBuildDefaults_NoRegister();
	APPEDITOR_API UClass* Z_Construct_UClass_UBuildDefaults();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_AppEditor();
// End Cross Module References
	void UBuildDefaults::StaticRegisterNativesUBuildDefaults()
	{
	}
	UClass* Z_Construct_UClass_UBuildDefaults_NoRegister()
	{
		return UBuildDefaults::StaticClass();
	}
	struct Z_Construct_UClass_UBuildDefaults_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBuildDefaults_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_AppEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBuildDefaults_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "BuildDefaults.h" },
		{ "ModuleRelativePath", "Public/BuildDefaults.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBuildDefaults_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBuildDefaults>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBuildDefaults_Statics::ClassParams = {
		&UBuildDefaults::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UBuildDefaults_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UBuildDefaults_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBuildDefaults()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBuildDefaults_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBuildDefaults, 476805615);
	template<> APPEDITOR_API UClass* StaticClass<UBuildDefaults>()
	{
		return UBuildDefaults::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBuildDefaults(Z_Construct_UClass_UBuildDefaults, &UBuildDefaults::StaticClass, TEXT("/Script/AppEditor"), TEXT("UBuildDefaults"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBuildDefaults);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
