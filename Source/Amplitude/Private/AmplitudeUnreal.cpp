#include "AmplitudeUnreal.h"
#include "AmplitudeProvider.h"
#include "Analytics.h"
#if PLATFORM_APPLE
#include "AmplitudeiOSBridge.h"
#endif

IMPLEMENT_MODULE(FAmplitudeUnreal, Amplitude)

TSharedPtr<IAnalyticsProvider> FAmplitudeProvider::AmplitudeProvider;
std::string LibraryName = "amplitude-unreal";

void FAmplitudeUnreal::StartupModule()
{
}

void FAmplitudeUnreal::ShutdownModule()
{
  FAmplitudeProvider::Destroy();
}

TSharedPtr<IAnalyticsProvider> FAmplitudeUnreal::CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate &GetConfigValue) const
{
  if (GetConfigValue.IsBound())
  {
    const FString Key = GetConfigValue.Execute(TEXT("AmplitudeApiKey"), true);
    return FAmplitudeProvider::Create(Key);
  }
  UE_LOG(LogAnalytics, Warning, TEXT("AmplitudeUnreal::CreateAnalyticsProvider was called with an unbound config delegate"));
  return nullptr;
}

FAmplitudeProvider::FAmplitudeProvider(const FString Key) : ApiKey(Key)
{
}
FAmplitudeProvider::~FAmplitudeProvider()
{
  if (bHasSessionStarted)
  {
    EndSession();
  }
}

bool FAmplitudeProvider::StartSession(const TArray<FAnalyticsEventAttribute> &Attributes)
{
#if PLATFORM_APPLE
  std::string ConvertedApiKey = std::string(TCHAR_TO_UTF8(*ApiKey));
  ios_bridge::AmplitudeiOSBridge Bridge;
  Bridge.initializeApiKey(ConvertedApiKey);
  Bridge.setLibrary(LibraryName);
#endif
  bHasSessionStarted = true;
  return bHasSessionStarted;
}

void FAmplitudeProvider::EndSession()
{
  bHasSessionStarted = false;
}

void FAmplitudeProvider::RecordEvent(const FString &EventName, const TArray<FAnalyticsEventAttribute> &Attributes)
{
  std::string ConvertedEventName = std::string(TCHAR_TO_UTF8(*EventName));
  std::vector<std::pair<std::string, std::string>> propertyPairs;
  for (FAnalyticsEventAttribute Attribute : Attributes)
  {
    std::pair<std::string, std::string> propertyPair;
    propertyPair.first = std::string(TCHAR_TO_UTF8(*Attribute.AttrName));
    propertyPair.second = std::string(TCHAR_TO_UTF8(*Attribute.AttrValueString));
    propertyPairs.push_back(propertyPair);
  }

#if PLATFORM_APPLE
  ios_bridge::AmplitudeiOSBridge Bridge;
  UE_LOG(LogAnalytics, Display, TEXT("[Amplitude Event] %s"), *EventName);
  Bridge.logEvent(ConvertedEventName, propertyPairs);
#endif
}

FString FAmplitudeProvider::GetSessionID() const
{
  return TEXT("NO-OP");
}

bool FAmplitudeProvider::SetSessionID(const FString &InSessionID)
{
  return true;
}

void FAmplitudeProvider::FlushEvents()
{
}

void FAmplitudeProvider::SetUserID(const FString &InUserID)
{
#if PLATFORM_APPLE
  ios_bridge::AmplitudeiOSBridge Bridge;
  std::string ConvertedUserName = std::string(TCHAR_TO_UTF8(*InUserID));
  Bridge.setUserId(ConvertedUserName);
#endif
}

FString FAmplitudeProvider::GetUserID() const
{
#if PLATFORM_APPLE
  ios_bridge::AmplitudeiOSBridge Bridge;
  FString userId = Bridge.getUserId().c_str();
  return userId;
#endif
  return TEXT("NO-OP");
}
