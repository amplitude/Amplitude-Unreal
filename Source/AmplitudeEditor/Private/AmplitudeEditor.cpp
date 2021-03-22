// Copyright Epic Games, Inc. All Rights Reserved.

#include "AmplitudeEditor.h"
#include "Modules/ModuleManager.h"
#include "AmplitudeSettings.h"
#include "Analytics.h"

IMPLEMENT_MODULE(FAmplitudeEditorModule, AmplitudeEditor);

#define LOCTEXT_NAMESPACE "Amplitude"

void FAmplitudeEditorModule::StartupModule()
{
}

void FAmplitudeEditorModule::ShutdownModule()
{
}

UAmplitudeSettings::UAmplitudeSettings(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
  SettingsDisplayName = LOCTEXT("SettingsDisplayName", "Amplitude");
  SettingsTooltip = LOCTEXT("SettingsTooltip", "Amplitude analytics configuration settings");
}

void UAmplitudeSettings::ReadConfigSettings()
{
  FString ReadApiKey = FAnalytics::Get().GetConfigValueFromIni(GetIniName(), GetReleaseIniSection(), TEXT("AmplitudeApiKey"), true);
  ReleaseApiKey = ReadApiKey;

  ReadApiKey = FAnalytics::Get().GetConfigValueFromIni(GetIniName(), GetDebugIniSection(), TEXT("AmplitudeApiKey"), true);
  if (ReadApiKey.Len() == 0)
  {
    ReadApiKey = ReleaseApiKey;
  }
  DebugApiKey = ReadApiKey;

  ReadApiKey = FAnalytics::Get().GetConfigValueFromIni(GetIniName(), GetTestIniSection(), TEXT("AmplitudeApiKey"), true);
  if (ReadApiKey.Len() == 0)
  {
    ReadApiKey = ReleaseApiKey;
  }
  TestApiKey = ReadApiKey;

  ReadApiKey = FAnalytics::Get().GetConfigValueFromIni(GetIniName(), GetDevelopmentIniSection(), TEXT("AmplitudeApiKey"), true);
  if (ReadApiKey.Len() == 0)
  {
    ReadApiKey = ReleaseApiKey;
  }
  DevelopmentApiKey = ReadApiKey;
}

void UAmplitudeSettings::WriteConfigSettings()
{
  FAnalytics::Get().WriteConfigValueToIni(GetIniName(), GetReleaseIniSection(), TEXT("AmplitudeApiKey"), ReleaseApiKey);
  FAnalytics::Get().WriteConfigValueToIni(GetIniName(), GetTestIniSection(), TEXT("AmplitudeApiKey"), TestApiKey);
  FAnalytics::Get().WriteConfigValueToIni(GetIniName(), GetDebugIniSection(), TEXT("AmplitudeApiKey"), DebugApiKey);
  FAnalytics::Get().WriteConfigValueToIni(GetIniName(), GetDevelopmentIniSection(), TEXT("AmplitudeApiKey"), DevelopmentApiKey);
}

#undef LOCTEXT_NAMESPACE
