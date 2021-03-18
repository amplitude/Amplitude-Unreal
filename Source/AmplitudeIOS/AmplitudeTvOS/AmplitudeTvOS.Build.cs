// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class AmplitudeTvOS : ModuleRules
{
  public AmplitudeTvOS(ReadOnlyTargetRules Target) : base(Target)
  {
    Type = ModuleType.External;
    PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));
    PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "arm64", "Amplitude_tvOS_Unreal.a"));
  }
}
