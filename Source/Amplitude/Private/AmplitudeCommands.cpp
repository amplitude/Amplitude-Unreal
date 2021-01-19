// Copyright Epic Games, Inc. All Rights Reserved.

#include "AmplitudeCommands.h"

#define LOCTEXT_NAMESPACE "FAmplitudeModule"

void FAmplitudeCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "Amplitude", "Execute Amplitude action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
