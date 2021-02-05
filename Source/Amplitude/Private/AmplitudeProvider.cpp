#include "AmplitudeProvider.h"
#include "Containers/UnrealString.h"
#include "Interfaces/IAnalyticsProvider.h"
#if PLATFORM_APPLE
  #include "AmplitudeiOSBridge.h"
#endif

FAmplitudeProvider::FAmplitudeProvider()
{
  
}
FAmplitudeProvider::~FAmplitudeProvider()
{
  EndSession();
}

bool FAmplitudeProvider::StartSession(const TArray<FAnalyticsEventAttribute>& Attributes)
{
  // ios_bridge::testEventSend();
  return true;
}

void FAmplitudeProvider::EndSession()
{
  
}

void FAmplitudeProvider::RecordEvent(const FString& EventName, const TArray<FAnalyticsEventAttribute>& Attributes)
{
  
}

FString FAmplitudeProvider::GetSessionID() const
{
  return TEXT("NO-OP");
}

bool FAmplitudeProvider::SetSessionID(const FString& InSessionID)
{
  return true;
}

void FAmplitudeProvider::FlushEvents()
{
  
}

void FAmplitudeProvider::SetUserID(const FString& InUserID)
{
  
}

FString FAmplitudeProvider::GetUserID() const
{
  return TEXT("NO-OP");
}
