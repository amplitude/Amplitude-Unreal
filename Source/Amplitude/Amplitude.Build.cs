using UnrealBuildTool;
using System.IO;
using System;
using Tools.DotNETCommon;

public class Amplitude : ModuleRules
{
  public Amplitude(ReadOnlyTargetRules Target) : base(Target)
  {
    PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
    string LibraryPath = Path.GetFullPath(Path.Combine(ModuleDirectory, "../Library"));
    Log.TraceInformation("In Amplitude.Build.cs");
    Log.TraceInformation(LibraryPath);
    Log.TraceInformation(ModuleDirectory);
    if (Target.Platform == UnrealTargetPlatform.IOS)
    {
      PrivateIncludePaths.AddRange(
        new string[] {
          Path.Combine(LibraryPath, "iOS", "x86_64", "Amplitude.framework", "Headers")
        }
      );
      PublicIncludePaths.AddRange(
        new string[] {
          Path.Combine(LibraryPath, "iOS", "x86_64", "Amplitude.framework", "Headers")
        }
      );
      PublicFrameworks.Add(Path.Combine(LibraryPath, "iOS", "x86_64", "Amplitude.framework"));
    }
    else
    {
      throw new NotImplementedException(Target.Platform.ToString() + " is not a supported target platform by the Amplitude Unreal SDK plugin");
    }

    PrivateIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "Private")));
    PrivateIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "Public")));
    PublicIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "Public")));

    PublicDependencyModuleNames.AddRange(
      new string[]
      {
        "Core",
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
