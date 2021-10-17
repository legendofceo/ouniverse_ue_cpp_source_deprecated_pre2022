// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class App : ModuleRules
{
	public App(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		//bUseRTTI = true;
		bUseUnity = false;
		MinFilesUsingPrecompiledHeaderOverride = 1;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "Slate", "SlateCore", "MediaAssets" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		string PathTo = "O:/sword/unreal/App5/";
		PublicIncludePaths.Add(PathTo + "Source/ThirdParty/");
		PublicIncludePaths.Add(PathTo + "Source/App/Game/Public/");
		PublicIncludePaths.Add(PathTo + "Source/App/Gui/Include/");
		PublicIncludePaths.Add(PathTo + "Source/App/Lua/");
		PublicIncludePaths.Add(PathTo + "Source/App/LuaBridge/");
		PublicIncludePaths.Add(PathTo + "Source/App/Module/Include/");

		PublicAdditionalLibraries.Add(PathTo+ "Source/App/Lua/liblua54_win64.lib");

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
