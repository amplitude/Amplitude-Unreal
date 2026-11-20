// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class AmplitudeTvOS : ModuleRules
{
  public AmplitudeTvOS(ReadOnlyTargetRules Target) : base(Target)
  {
    Type = ModuleType.External;
    
    // UE5 compatibility settings
    PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
    // CppStandard = CppStandardVersion.Cpp20;
    
    PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));
    PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "arm64", "Amplitude_tvOS_Unreal.a"));
    PublicDefinitions.Add("AMPLITUDE_USE_PREFIXED_SERVERZONE=1");
  
    // tvOS specific framework dependencies
    if (Target.Platform == UnrealTargetPlatform.TVOS)
    {
      PublicFrameworks.AddRange(new string[]
      {
        "Foundation",
        "SystemConfiguration"
      });
    }
  }
}
