// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class one : ModuleRules
{
	public one(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		//MinFilesUsingPrecompiledHeaderOverride = 1;
		//bFasterWithoutUnity = true;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "Http", "CinematicCamera", "LuaMachine" });

		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		PublicIncludePaths.Add("O:/one/ue/one/Source/external/");
		//PublicIncludePaths.AddRange(new string[] { "<LuaMachine>/Public", "<LuaMachine>/Private" });
	}
}
