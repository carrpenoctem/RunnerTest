// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RunnerTest : ModuleRules
{
	public RunnerTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
