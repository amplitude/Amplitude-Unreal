// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "AmplitudeStyle.h"

class FAmplitudeCommands : public TCommands<FAmplitudeCommands>
{
public:

	FAmplitudeCommands()
		: TCommands<FAmplitudeCommands>(TEXT("Amplitude"), NSLOCTEXT("Contexts", "Amplitude", "Amplitude Plugin"), NAME_None, FAmplitudeStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
