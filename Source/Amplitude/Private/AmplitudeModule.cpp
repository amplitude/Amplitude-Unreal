#include "AmplitudeModule.h"
#include "AmplitudeProvider.h"

// static const FName AmplitudeTabName("Amplitude");

#define LOCTEXT_NAMESPACE "FAmplitudeModule"

TSharedPtr<IAnalyticsProvider> FAmplitudeModule::CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate &GetConfigValue) const 
{
  return MakeShareable(new FAmplitudeProvider());
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAmplitudeModule, Amplitude)
