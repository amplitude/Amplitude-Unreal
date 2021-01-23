#pragma once

#include "Containers/UnrealString.h"
#include "Interfaces/IAnalyticsProvider.h"

class FAmplitudeProvider : public IAnalyticsProvider
{
public:
	FAmplitudeProvider();
	virtual ~FAmplitudeProvider();

	bool StartSession(const TArray<FAnalyticsEventAttribute>& Attributes) override;

	void EndSession() override;

	void RecordEvent(const FString& EventName, const TArray<FAnalyticsEventAttribute>& Attributes) override;

	FString GetSessionID() const override;

	bool SetSessionID(const FString& InSessionID) override;

	void FlushEvents() override;

	void SetUserID(const FString& InUserID) override;

	FString GetUserID() const override;
};