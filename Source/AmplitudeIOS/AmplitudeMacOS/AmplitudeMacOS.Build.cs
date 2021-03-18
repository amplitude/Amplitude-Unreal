// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class AmplitudeMacOS : ModuleRules
{
  public AmplitudeMacOS(ReadOnlyTargetRules Target) : base(Target)
  {
    Type = ModuleType.External;
    PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));
    PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "Amplitude_macOS_Unreal.a"));
  }
}
