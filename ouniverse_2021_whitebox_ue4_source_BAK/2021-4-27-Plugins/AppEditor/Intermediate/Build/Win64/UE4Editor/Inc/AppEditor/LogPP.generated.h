// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef APPEDITOR_LogPP_generated_h
#error "LogPP.generated.h already included, missing '#pragma once' in LogPP.h"
#endif
#define APPEDITOR_LogPP_generated_h

#define App_Plugins_AppEditor_Source_AppEditor_Public_LogPP_h_79_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLogPP_Statics; \
	static class UScriptStruct* StaticStruct();


template<> APPEDITOR_API UScriptStruct* StaticStruct<struct FLogPP>();

#define App_Plugins_AppEditor_Source_AppEditor_Public_LogPP_h_35_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLogEntryPP_Statics; \
	APPEDITOR_API static class UScriptStruct* StaticStruct();


template<> APPEDITOR_API UScriptStruct* StaticStruct<struct FLogEntryPP>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID App_Plugins_AppEditor_Source_AppEditor_Public_LogPP_h


#define FOREACH_ENUM_LOGVERBPP(op) \
	op(LogVerbPP::None) \
	op(LogVerbPP::Light) \
	op(LogVerbPP::Medium) \
	op(LogVerbPP::Heavy) \
	op(LogVerbPP::Massive) \
	op(LogVerbPP::OMFG) 

enum class LogVerbPP : uint8;
template<> APPEDITOR_API UEnum* StaticEnum<LogVerbPP>();

#define FOREACH_ENUM_LOGTYPEPP(op) \
	op(LogTypePP::Normal) \
	op(LogTypePP::Warning) \
	op(LogTypePP::Critical) \
	op(LogTypePP::Header) \
	op(LogTypePP::Note) 

enum class LogTypePP : uint8;
template<> APPEDITOR_API UEnum* StaticEnum<LogTypePP>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
