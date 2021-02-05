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
    if (Target.Platform == UnrealTargetPlatform.Mac)
    {
      PrivateIncludePaths.AddRange(
        new string[] {
          // Path.Combine(LibraryPath, "iOS", "Headers")
          Path.Combine(LibraryPath, "iOS", "x86_64", "Amplitude.framework", "Headers")
          // ... add public include paths required here ...
        }
      );
      PublicIncludePaths.AddRange(
        new string[] {
          Path.Combine(LibraryPath, "iOS", "x86_64", "Amplitude.framework", "Headers")
          // ... add public include paths required here ...
        }
      );
      PublicFrameworks.Add(Path.Combine(LibraryPath, "iOS", "x86_64", "Amplitude.framework"));
          
      PublicFrameworks.AddRange(
          new string[] {
              "AdSupport",
              "SystemConfiguration"
          }
      );
    } else
    {
      throw new NotImplementedException(Target.Platform.ToString() + " is not a supported target platform by the Amplitude Unreal SDK plugin");
    }

    // PrivateIncludePaths.AddRange(
    //   new string[] {
    //     Path.Combine(LibraryPath, "iOS")
    //     // ... add public include paths required here ...
    //   }
    // );
          

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
      // var ModulePath = Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name));
      // Log.TraceInformation(ModuleDirectory);

      PrivateIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "Private")));
      PrivateIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "Public")));
      PublicIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "Public")));
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
        "CoreUObject",
        "Engine",
        "Amplitude",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// "Projects",
				// "InputCore",
				// "UnrealEd",
        // "Analytics",
				// "ToolMenus",
				// "CoreUObject",
				// "Engine",
				// "Slate",
				// "SlateCore",
        "Amplitude",
				// ... add private dependencies that you statically link with here ...	
			}
    );
    
    PublicIncludePathModuleNames.AddRange(
      new string[]
      {
          "Analytics",
          "Engine"
      }
    );
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
