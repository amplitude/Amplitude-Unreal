#include "AmplitudeUnreal.h"
#include "AmplitudeProvider.h"

static const FName AmplitudeTabName("Amplitude");

#define LOCTEXT_NAMESPACE "FAmplitudeUnreal"

TSharedPtr<IAnalyticsProvider> FAmplitudeUnreal::CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate &GetConfigValue) const 
{
  return MakeShareable(new FAmplitudeProvider());
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAmplitudeUnreal, Amplitude)
