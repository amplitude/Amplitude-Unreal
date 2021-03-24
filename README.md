# AmplitudeUnreal

Unreal Engine 4 plug-in that adds Amplitude support to game development
## Supported Platforms

This plug-in was last built against **Unreal Engine 4.25.4**. 
<!-- @TODO: Add siOS and Android when they're done -->

## Usage

You can use this plug-in as a project plug-in, or an Engine plug-in.

If you use it as a project plug-in, clone this repository into your project's
*/Plugins* directory and compile your game in Visual Studio. A C++ code project
is required for this to work.

If you use it as an Engine plug-in, clone this repository into the
*/Engine/Plugins/Media* directory and compile your game. Full Unreal Engine 4
source code from GitHub (4.9 or higher) is required for this.

## References

* [Introduction to UE4 Plugins](https://wiki.unrealengine.com/An_Introduction_to_UE4_Plugins)

## Development Tips

- [MacOS Setup Guide](https://github.com/botman99/ue4-xcode-vscode-mac)
- If you are new to programming in UE4, please see the Epic's [Programming Guide](https://docs.unrealengine.com/latest/INT/Programming/index.html)! 
- Hot Reload: Source code updates should be compiled before reflecting in the editor. Thus, you should do: Window -> Developer Tools -> Modules -> Search `Amplitude` -> Recompile -> Reload. Otherwise, you'll need to restart your UE4Editor
- VSCode Development: By default, UE4 selects XCode as your editor
- Unreal Engine Source Code: Unreal's source code is open source, but you must [link your Epic account to Github](https://www.unrealengine.com/en-US/ue4-on-github).

## Client Usage

1. Make sure the plugin is installed.

```bash
mkdir -p Plugins
cd Plugins
git clone git@github.com:amplitude/Amplitude-Unreal.git Amplitude-Unreal
```

2. Go to Settings -> Plugins -> Project -> Analytics and make sure Amplitude is enabled

![image](https://user-images.githubusercontent.com/15751908/107719580-68d65e80-6c8d-11eb-86a1-1e748fd263e7.png)

3. Go to Settings -> Project Settings -> Analytics -> Provider to make sure values are set to `Amplitude`

4. Go to Settings -> Project Settings -> Analytics -> Amplitude to add your API Keys

5. Start instrumenting your UE4 application, for example:

```c++
/* Include analytics headers */
// ...
#include "Analytics.h"
#include "Interfaces/IAnalyticsProvider.h"
// ...

/* Follow generic APIs for IAnalyticsProvider */
FAnalytics::Get().GetDefaultConfiguredProvider()->StartSession();
FAnalytics::Get().GetDefaultConfiguredProvider()->RecordEvent(TEXT("Game started"));
FAnalytics::Get().GetDefaultConfiguredProvider()->EndSession();
```
