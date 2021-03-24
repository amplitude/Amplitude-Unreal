#include "AmplitudeUnreal.h"
#include "AmplitudeProvider.h"
#include "Analytics.h"
#include <exception>
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
#if PLATFORM_APPLE
  ios_bridge::AmplitudeiOSBridge Bridge;
  FString SessionId = FString::SanitizeFloat(Bridge.getSessionId());
  return SessionId;
#endif
}

bool FAmplitudeProvider::SetSessionID(const FString &InSessionID)
{
  try
  {
#if PLATFORM_APPLE
    ios_bridge::AmplitudeiOSBridge Bridge;
    long ConvertedSessionId = std::stoi(std::string(TCHAR_TO_UTF8(*InSessionID)));
    Bridge.setSessionId(ConvertedSessionId);
#endif
    return true;
  }
  catch (std::exception &e)
  {
    return false;
  }
}

void FAmplitudeProvider::FlushEvents()
{
#if PLATFORM_APPLE
  ios_bridge::AmplitudeiOSBridge Bridge;
  Bridge.uploadEvents();
#endif
}

void FAmplitudeProvider::SetUserID(const FString &InUserID)
{
#if PLATFORM_APPLE
  ios_bridge::AmplitudeiOSBridge Bridge;
  std::string ConvertedUserId = std::string(TCHAR_TO_UTF8(*InUserID));
  Bridge.setUserId(ConvertedUserId);
#endif
}

FString FAmplitudeProvider::GetUserID() const
{
#if PLATFORM_APPLE
  ios_bridge::AmplitudeiOSBridge Bridge;
  FString BridgedUserId = Bridge.getUserId().c_str();
  return BridgedUserId;
#endif
  return TEXT("NO-OP");
}

void FAmplitudeProvider::SetUserProperty(const FString &Property, const FString &Value)
{
  std::string ConvertedProperty = std::string(TCHAR_TO_UTF8(*Property));
  std::string ConvertedValue = std::string(TCHAR_TO_UTF8(*Value));

#if PLATFORM_APPLE
  ios_bridge::AmplitudeiOSBridge Bridge;
  Bridge.setUserProperty(ConvertedProperty, ConvertedValue);
#endif
}

void FAmplitudeProvider::SetLocation(const FString &InLocation)
{
  SetUserProperty(TEXT("Location"), InLocation);
}

void FAmplitudeProvider::SetGender(const FString &InGender)
{
  SetUserProperty(TEXT("Gender"), InGender);
}

void FAmplitudeProvider::SetAge(const int32 InAge)
{
  SetUserProperty(TEXT("Age"), FString::FromInt(InAge));
}
