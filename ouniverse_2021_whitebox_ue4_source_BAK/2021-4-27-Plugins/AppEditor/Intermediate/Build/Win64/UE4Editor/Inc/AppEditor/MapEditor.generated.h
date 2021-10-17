// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FAssetData;
#ifdef APPEDITOR_MapEditor_generated_h
#error "MapEditor.generated.h already included, missing '#pragma once' in MapEditor.h"
#endif
#define APPEDITOR_MapEditor_generated_h

#define App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_SPARSE_DATA
#define App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execBloomMapData);


#define App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execBloomMapData);


#define App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMapEditor(); \
	friend struct Z_Construct_UClass_UMapEditor_Statics; \
public: \
	DECLARE_CLASS(UMapEditor, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AppEditor"), NO_API) \
	DECLARE_SERIALIZER(UMapEditor)


#define App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUMapEditor(); \
	friend struct Z_Construct_UClass_UMapEditor_Statics; \
public: \
	DECLARE_CLASS(UMapEditor, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AppEditor"), NO_API) \
	DECLARE_SERIALIZER(UMapEditor)


#define App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMapEditor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMapEditor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMapEditor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMapEditor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMapEditor(UMapEditor&&); \
	NO_API UMapEditor(const UMapEditor&); \
public:


#define App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMapEditor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMapEditor(UMapEditor&&); \
	NO_API UMapEditor(const UMapEditor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMapEditor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMapEditor); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMapEditor)


#define App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_PRIVATE_PROPERTY_OFFSET
#define App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_15_PROLOG
#define App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_PRIVATE_PROPERTY_OFFSET \
	App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_SPARSE_DATA \
	App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_RPC_WRAPPERS \
	App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_INCLASS \
	App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_PRIVATE_PROPERTY_OFFSET \
	App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_SPARSE_DATA \
	App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_INCLASS_NO_PURE_DECLS \
	App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> APPEDITOR_API UClass* StaticClass<class UMapEditor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID App_Plugins_AppEditor_Source_AppEditor_Public_MapEditor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
