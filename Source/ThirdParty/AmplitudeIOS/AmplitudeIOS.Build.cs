// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class AmplitudeIOS : ModuleRules
{
	public AmplitudeIOS(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
    PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "libAmplitude_macOS_static_lib.a"));
	}
}
