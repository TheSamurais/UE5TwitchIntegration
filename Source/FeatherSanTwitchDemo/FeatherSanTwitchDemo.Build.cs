// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FeatherSanTwitchDemo : ModuleRules
{
	public FeatherSanTwitchDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        CppStandard = CppStandardVersion.Cpp17;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG", "Slate" });

		PrivateDependencyModuleNames.Add("TwitchSDK");
	}
}
