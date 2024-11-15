// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class examen : ModuleRules
{
	public examen(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
