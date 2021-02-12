#pragma once

#include "Containers/UnrealString.h"
#include "Interfaces/IAnalyticsProvider.h"
#include <string>

class FAmplitudeProvider : public IAnalyticsProvider
{
    /** The API key for your Amplitude project */
	FString ApiKey;
	/** Tracks whether we need to start the session or restart it */
	bool bHasSessionStarted;
	/** Cached user id */
	FString UserId;

  /** Singleton for analytics */
  static TSharedPtr<IAnalyticsProvider> AmplitudeProvider;

public:
  FAmplitudeProvider(const FString Key);
	virtual ~FAmplitudeProvider();

  static TSharedPtr<IAnalyticsProvider> Create(const FString Key)
	{
		if (!AmplitudeProvider.IsValid())
		{
			AmplitudeProvider = TSharedPtr<IAnalyticsProvider>(new FAmplitudeProvider(Key));
		}
		return AmplitudeProvider;
	}

	static void Destroy()
	{
		AmplitudeProvider.Reset();
	}


	virtual bool StartSession(const TArray<FAnalyticsEventAttribute>& Attributes) override;

	virtual void EndSession() override;

	virtual void RecordEvent(const FString& EventName, const TArray<FAnalyticsEventAttribute>& Attributes) override;

	virtual FString GetSessionID() const override;

	virtual bool SetSessionID(const FString& InSessionID) override;

	virtual void FlushEvents() override;

	virtual void SetUserID(const FString& InUserID) override;

	virtual FString GetUserID() const override;
};