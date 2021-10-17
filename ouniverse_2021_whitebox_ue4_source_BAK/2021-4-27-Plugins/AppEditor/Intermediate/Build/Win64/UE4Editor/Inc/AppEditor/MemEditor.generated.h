// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FAssetData;
#ifdef APPEDITOR_MemEditor_generated_h
#error "MemEditor.generated.h already included, missing '#pragma once' in MemEditor.h"
#endif
#define APPEDITOR_MemEditor_generated_h

#define App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_SPARSE_DATA
#define App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execBloomMemFlags);


#define App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execBloomMemFlags);


#define App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMemEditor(); \
	friend struct Z_Construct_UClass_UMemEditor_Statics; \
public: \
	DECLARE_CLASS(UMemEditor, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AppEditor"), NO_API) \
	DECLARE_SERIALIZER(UMemEditor)


#define App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUMemEditor(); \
	friend struct Z_Construct_UClass_UMemEditor_Statics; \
public: \
	DECLARE_CLASS(UMemEditor, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AppEditor"), NO_API) \
	DECLARE_SERIALIZER(UMemEditor)


#define App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMemEditor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMemEditor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMemEditor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMemEditor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMemEditor(UMemEditor&&); \
	NO_API UMemEditor(const UMemEditor&); \
public:


#define App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMemEditor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMemEditor(UMemEditor&&); \
	NO_API UMemEditor(const UMemEditor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMemEditor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMemEditor); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMemEditor)


#define App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_PRIVATE_PROPERTY_OFFSET
#define App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_15_PROLOG
#define App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_PRIVATE_PROPERTY_OFFSET \
	App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_SPARSE_DATA \
	App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_RPC_WRAPPERS \
	App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_INCLASS \
	App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_PRIVATE_PROPERTY_OFFSET \
	App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_SPARSE_DATA \
	App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_INCLASS_NO_PURE_DECLS \
	App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> APPEDITOR_API UClass* StaticClass<class UMemEditor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID App_Plugins_AppEditor_Source_AppEditor_Public_MemEditor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
