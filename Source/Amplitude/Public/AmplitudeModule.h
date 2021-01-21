// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IAnalyticsProviderModule.h"

class FAmplitudeModule : public IAnalyticsProviderModule
{
public:
	
private:

private:
    TSharedPtr < IAnalyticsProvider > CreateAnalyticsProvider ( const FAnalyticsProviderConfigurationDelegate & GetConfigValue ) const override;
};
