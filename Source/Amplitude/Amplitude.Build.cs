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
    PublicDefinitions.Add("WITH_AMPLITUDE1");
    if (Target.Platform == UnrealTargetPlatform.Mac)
    {
      // PrivateIncludePaths.AddRange(
      //   new string[] {
      //    Path.Combine(ModuleDirectory, "include")
      //   }
      // );
      // PublicIncludePaths.AddRange(
      //   new string[] {
      //     Path.Combine(ModuleDirectory, "include")
      //   }
      // );
      Log.TraceInformation(Path.Combine(ModuleDirectory, "include"));
      
      // PublicAdditionalFrameworks.Add(
      //   Path.Combine(ThirdPartyPath, "iOS", "x86_64", "Amplitude.framework"
      // ));
      // Log.TraceInformation(Path.Combine(ThirdPartyPath, "Amplitude-iOS", "x86_64", "Amplitude.embeddedframework.zip"));
      // Log.TraceInformation(Path.Combine(ThirdPartyPath, "Amplitude-iOS", "x86_64", "Headers"));
      // RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "lib/IOS/libdynamic.framework/libdynamic"), UnrealBuildTool.StagedFileType.SystemNonUFS);
      // PublicSystemIncludePaths.AddRange(
      //   new string[] {
      //     Path.Combine(ThirdPartyPath, "Amplitude-iOS", "include")
      //   }
      // );
      // PublicAdditionalFrameworks.Add(
			// 	new Framework(
			// 		"Amplitude",
			// 		Path.Combine(ThirdPartyPath, "Amplitude-iOS", "x86_64", "Amplitude.embeddedframework.zip")
      //     // "../Library/Amplitude-iOS/x86_64/Amplitude.embeddedframework.zip"
			// 	)
			// );
      // PublicFrameworks.Add(Path.Combine(ThirdPartyPath, "Amplitude-iOS", "x86_64", "Amplitude.framework"));
      // RuntimeDependencies.Add(Path.Combine(ThirdPartyPath, "Amplitude-iOS", "x86_64", "Amplitude.framework", "Amplitude"));
      // PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "lib", "libAmplitude_macOS_static_lib.a"));
      // RuntimeDependencies.Add("$(PluginDir)/Source/ThirdParty/lib/libAmplitude_macOS_static_lib.a");
      PublicDependencyModuleNames.AddRange(
        new string[]
        {
          "AmplitudeIOS"
        }
      );
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
