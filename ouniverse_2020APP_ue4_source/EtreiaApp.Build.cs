// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EtreiaApp : ModuleRules
{
	public EtreiaApp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		//MinFilesUsingPrecompiledHeaderOverride = 1;
		//bFasterWithoutUnity = true;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "Http", "CinematicCamera"});

		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		PublicIncludePaths.Add("O:/etreia/ue/EtreiaApp/Source/external/");
	}
}
