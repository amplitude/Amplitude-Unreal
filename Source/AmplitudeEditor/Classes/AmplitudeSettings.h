// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "AnalyticsSettings.h"
#include "AmplitudeSettings.generated.h"

UCLASS()
class UAmplitudeSettings
	: public UAnalyticsSettingsBase
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category=Amplitude, meta=(ConfigRestartRequired=true))
	FString ReleaseApiKey;

	UPROPERTY(EditAnywhere, Category=Amplitude, meta=(ConfigRestartRequired=true))
	FString DebugApiKey;

	UPROPERTY(EditAnywhere, Category=Amplitude, meta=(ConfigRestartRequired=true))
	FString TestApiKey;

	UPROPERTY(EditAnywhere, Category=Amplitude, meta=(ConfigRestartRequired=true))
	FString DevelopmentApiKey;

// UAnalyticsSettingsBase interface
protected:
	/**
	 * Provides a mechanism to read the section based information into this UObject's properties
	 */
	virtual void ReadConfigSettings();
	/**
	 * Provides a mechanism to save this object's properties to the section based ini values
	 */
	virtual void WriteConfigSettings();
};
