// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef APPEDITOR_EditorEnums_generated_h
#error "EditorEnums.generated.h already included, missing '#pragma once' in EditorEnums.h"
#endif
#define APPEDITOR_EditorEnums_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID App_Plugins_AppEditor_Source_AppEditor_Public_EditorEnums_h


#define FOREACH_ENUM_EEDITORSUCCESSEXECS(op) \
	op(EEditorSuccessExecs::Success) \
	op(EEditorSuccessExecs::Fail) 

enum class EEditorSuccessExecs : uint8;
template<> APPEDITOR_API UEnum* StaticEnum<EEditorSuccessExecs>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
