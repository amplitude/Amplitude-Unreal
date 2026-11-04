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
  
  // Add default attributes first
  for (const FAnalyticsEventAttribute& DefaultAttribute : DefaultEventAttributes)
  {
    std::pair<std::string, std::string> propertyPair;
    propertyPair.first = std::string(TCHAR_TO_UTF8(*DefaultAttribute.GetName()));
    propertyPair.second = std::string(TCHAR_TO_UTF8(*DefaultAttribute.GetValue()));
    propertyPairs.push_back(propertyPair);
  }
  
  // Add event-specific attributes
  for (const FAnalyticsEventAttribute& Attribute : Attributes)
  {
    std::pair<std::string, std::string> propertyPair;
    propertyPair.first = std::string(TCHAR_TO_UTF8(*Attribute.GetName()));
    propertyPair.second = std::string(TCHAR_TO_UTF8(*Attribute.GetValue()));
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
  return TEXT("-1");
}

bool FAmplitudeProvider::SetSessionID(const FString &InSessionID)
{
  // Use Unreal's string conversion instead of std::stoi to avoid exceptions
  if (InSessionID.IsNumeric())
  {
#if PLATFORM_APPLE
    ios_bridge::AmplitudeiOSBridge Bridge;
    long ConvertedSessionId = FCString::Atoi64(*InSessionID);
    Bridge.setSessionId(ConvertedSessionId);
#endif
    return true;
  }
  
  // Log error and return false if the session ID is not numeric
  UE_LOG(LogAnalytics, Warning, TEXT("SetSessionID failed: Invalid session ID format: %s"), *InSessionID);
  return false;
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

void FAmplitudeProvider::SetDefaultEventAttributes(TArray<FAnalyticsEventAttribute>&& Attributes)
{
  DefaultEventAttributes = MoveTemp(Attributes);
}

TArray<FAnalyticsEventAttribute> FAmplitudeProvider::GetDefaultEventAttributesSafe() const
{
  return DefaultEventAttributes;
}

int32 FAmplitudeProvider::GetDefaultEventAttributeCount() const
{
  return DefaultEventAttributes.Num();
}

FAnalyticsEventAttribute FAmplitudeProvider::GetDefaultEventAttribute(int AttributeIndex) const
{
  return DefaultEventAttributes[AttributeIndex];
}
