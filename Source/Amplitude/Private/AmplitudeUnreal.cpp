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
#if PLATFORM_APPLE
  ios_bridge::AmplitudeiOSBridge Bridge;
  std::string ConvertedEventName = std::string(TCHAR_TO_UTF8(*EventName));
  UE_LOG(LogAnalytics, Display, TEXT("[Amplitude Event] %s"), *EventName);
  Bridge.logEvent(ConvertedEventName);
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
