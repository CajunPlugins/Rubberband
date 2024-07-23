// Copyright 2024 Cajun Pro LLC. All Rights Reserved.

using UnrealBuildTool;

public class Rubberband : ModuleRules
{
	public  Rubberband(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new [] { "Core" });
		PrivateDependencyModuleNames.AddRange(new [] { "CoreUObject", "Engine" });
	}
}
