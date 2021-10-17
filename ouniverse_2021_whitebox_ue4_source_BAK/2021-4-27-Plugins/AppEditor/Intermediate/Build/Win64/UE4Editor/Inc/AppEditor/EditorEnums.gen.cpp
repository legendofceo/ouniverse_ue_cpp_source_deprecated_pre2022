// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AppEditor/Public/EditorEnums.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEditorEnums() {}
// Cross Module References
	APPEDITOR_API UEnum* Z_Construct_UEnum_AppEditor_EEditorSuccessExecs();
	UPackage* Z_Construct_UPackage__Script_AppEditor();
// End Cross Module References
	static UEnum* EEditorSuccessExecs_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_AppEditor_EEditorSuccessExecs, Z_Construct_UPackage__Script_AppEditor(), TEXT("EEditorSuccessExecs"));
		}
		return Singleton;
	}
	template<> APPEDITOR_API UEnum* StaticEnum<EEditorSuccessExecs>()
	{
		return EEditorSuccessExecs_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EEditorSuccessExecs(EEditorSuccessExecs_StaticEnum, TEXT("/Script/AppEditor"), TEXT("EEditorSuccessExecs"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_AppEditor_EEditorSuccessExecs_Hash() { return 1689699356U; }
	UEnum* Z_Construct_UEnum_AppEditor_EEditorSuccessExecs()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_AppEditor();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EEditorSuccessExecs"), 0, Get_Z_Construct_UEnum_AppEditor_EEditorSuccessExecs_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EEditorSuccessExecs::Success", (int64)EEditorSuccessExecs::Success },
				{ "EEditorSuccessExecs::Fail", (int64)EEditorSuccessExecs::Fail },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Fail.Name", "EEditorSuccessExecs::Fail" },
				{ "ModuleRelativePath", "Public/EditorEnums.h" },
				{ "Success.Name", "EEditorSuccessExecs::Success" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_AppEditor,
				nullptr,
				"EEditorSuccessExecs",
				"EEditorSuccessExecs",
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
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
