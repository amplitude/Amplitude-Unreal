// Copyright Epic Games, Inc. All Rights Reserved.

#include "Amplitude.h"
#include "AmplitudeStyle.h"
#include "AmplitudeCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName AmplitudeTabName("Amplitude");

#define LOCTEXT_NAMESPACE "FAmplitudeModule"

void FAmplitudeModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FAmplitudeStyle::Initialize();
	FAmplitudeStyle::ReloadTextures();

	FAmplitudeCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FAmplitudeCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FAmplitudeModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FAmplitudeModule::RegisterMenus));
}

void FAmplitudeModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FAmplitudeStyle::Shutdown();

	FAmplitudeCommands::Unregister();
}

void FAmplitudeModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FAmplitudeModule::PluginButtonClicked()")),
							FText::FromString(TEXT("Amplitude.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FAmplitudeModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FAmplitudeCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FAmplitudeCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAmplitudeModule, Amplitude)