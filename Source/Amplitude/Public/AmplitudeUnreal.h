#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IAnalyticsProviderModule.h"

class FAmplitudeUnreal : public IAnalyticsProviderModule
{
public:
	
private:

private:
    TSharedPtr < IAnalyticsProvider > CreateAnalyticsProvider ( const FAnalyticsProviderConfigurationDelegate & GetConfigValue ) const override;
};
