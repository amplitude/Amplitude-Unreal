// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
using System;

public class AmplitudeEditor : ModuleRules
{
  public AmplitudeEditor(ReadOnlyTargetRules Target) : base(Target)
  {
    // PrivateIncludePaths.Add("AmplitudeEditor/Private");
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
