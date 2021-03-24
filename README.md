<p align="center">
  <a href="https://amplitude.com" target="_blank" align="center">
    <img src="https://static.amplitude.com/lightning/46c85bfd91905de8047f1ee65c7c93d6fa9ee6ea/static/media/amplitude-logo-with-text.4fb9e463.svg" width="280">
  </a>
  </br>
  <img alt="GitHub release (latest SemVer)" src="https://img.shields.io/github/v/release/amplitude/amplitude-unreal">
  <h1 align="center">🛠️ IN BETA 🛠️</h1>
</p>

# Official Amplitude SDK/Plugin for the Unreal Engine

Unreal Engine 4 plug-in that adds [Amplitude](https://www.amplitude.com) analytics support to game development.

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
