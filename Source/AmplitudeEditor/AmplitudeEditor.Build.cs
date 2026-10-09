// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
using System;

public class AmplitudeEditor : ModuleRules
{
  public AmplitudeEditor(ReadOnlyTargetRules Target) : base(Target)
  {
    // UE5 compatibility settings
    PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
    // CppStandard = CppStandardVersion.Cpp20;
    
    // Include paths
    PrivateIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "Private")));
    PrivateIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "Public")));
    PublicIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "Public")));

    PrivateDependencyModuleNames.AddRange(
      new string[] {
        "Core",
        "CoreUObject",
        "Analytics",
        "AnalyticsVisualEditing",
        "Engine",
        "Projects",
        "Slate",
        "SlateCore",
        "EditorStyle",
        "EditorWidgets",
        "UnrealEd",
        "WorkspaceMenuStructure",
        "DeveloperSettings"
      }
    );

    PrivateIncludePathModuleNames.AddRange(
      new string[] {
        "Settings"
      }
    );
  }
}
