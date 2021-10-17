// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDataTable;
struct FLogPP;
#ifdef APPEDITOR_CompanionEditor_generated_h
#error "CompanionEditor.generated.h already included, missing '#pragma once' in CompanionEditor.h"
#endif
#define APPEDITOR_CompanionEditor_generated_h

#define App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_SPARSE_DATA
#define App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execProcessCompanionData);


#define App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execProcessCompanionData);


#define App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCompanionEditor(); \
	friend struct Z_Construct_UClass_UCompanionEditor_Statics; \
public: \
	DECLARE_CLASS(UCompanionEditor, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AppEditor"), NO_API) \
	DECLARE_SERIALIZER(UCompanionEditor)


#define App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_INCLASS \
private: \
	static void StaticRegisterNativesUCompanionEditor(); \
	friend struct Z_Construct_UClass_UCompanionEditor_Statics; \
public: \
	DECLARE_CLASS(UCompanionEditor, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AppEditor"), NO_API) \
	DECLARE_SERIALIZER(UCompanionEditor)


#define App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCompanionEditor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCompanionEditor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCompanionEditor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCompanionEditor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCompanionEditor(UCompanionEditor&&); \
	NO_API UCompanionEditor(const UCompanionEditor&); \
public:


#define App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCompanionEditor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCompanionEditor(UCompanionEditor&&); \
	NO_API UCompanionEditor(const UCompanionEditor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCompanionEditor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCompanionEditor); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCompanionEditor)


#define App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_PRIVATE_PROPERTY_OFFSET
#define App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_16_PROLOG
#define App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_PRIVATE_PROPERTY_OFFSET \
	App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_SPARSE_DATA \
	App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_RPC_WRAPPERS \
	App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_INCLASS \
	App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_PRIVATE_PROPERTY_OFFSET \
	App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_SPARSE_DATA \
	App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_INCLASS_NO_PURE_DECLS \
	App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> APPEDITOR_API UClass* StaticClass<class UCompanionEditor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID App_Plugins_AppEditor_Source_AppEditor_Public_CompanionEditor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
