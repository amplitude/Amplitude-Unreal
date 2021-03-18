using UnrealBuildTool;
using System.IO;
using System;
using Tools.DotNETCommon;

public class Amplitude : ModuleRules
{
  public Amplitude(ReadOnlyTargetRules Target) : base(Target)
  {
    PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
    string ThirdPartyPath = Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty"));
    Log.TraceInformation("In Amplitude.Build.cs");
    Log.TraceInformation(ThirdPartyPath);
    PublicDefinitions.Add("WITH_AMPLITUDE=1");
    if (Target.Platform == UnrealTargetPlatform.Mac)
    {
      PrivateDependencyModuleNames.Add("AmplitudeMacOS");
    }
    else if (Target.Platform == UnrealTargetPlatform.IOS)
    {
      PrivateDependencyModuleNames.Add("AmplitudeIOS");
    }
    else if (Target.Platform == UnrealTargetPlatform.TVOS)
    {
      PrivateDependencyModuleNames.Add("AmplitudeTVOS");
    }
    else
    {
      throw new NotImplementedException(Target.Platform.ToString() + " is not a supported target platform by the Amplitude Unreal SDK plugin");
    }

    PrivateIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "Private")));
    PrivateIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "Public")));

    PublicDependencyModuleNames.AddRange(
      new string[]
      {
        "Core",
        "CoreUObject",
        "Engine",
      }
      );


    PrivateDependencyModuleNames.AddRange(
      new string[]
      {
        "Analytics",
      }
    );

    PublicIncludePathModuleNames.AddRange(
      new string[]
      {
        "Analytics",
      }
    );
  }
}
