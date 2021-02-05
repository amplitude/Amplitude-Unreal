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
- Unreal Engine Source Code: Unreal's source code is open source, but you must [https://www.unrealengine.com/en-US/ue4-on-github](link your Epic account to Github)


AmplitudeIOS-C-Interface.h = MyObject-C-Interface.h = // Common C-only interface understood by both ObjC and C++
Amplitude.h = MyObject.h = // Header for iOS file. Difference is that AmplitudeIOS-C-Interface.h needs to be imported
iOSBridge.mm = MyObject.mm == // Should have struct containg AmplitudeIOS

AmplitudeiOSBridge.h == PersonImpl.h == C++ header that Provider will itnerface with
iOSBridge.mm = Person.mm == // Should have struct contaiing PersonImpl/AmplitudeiOSBridge. Adapts calls to fit with iOS API (e.g. convert arg types and pass it along)
namespace ios_bridge == namespace people == // namespace to distinguish from ObjC class

Object files from Xcode were fine, built for right architecture
Linking and calling iOS code was fine
Problem was because Header wasn't 
Unreal saw Test.h and saw it should be looking for Test.mm.o
Unreal tried to link Test.c.o instead of Test.mm.o

commits
- replacing soruce files with .framework
- change name of Amplitude.cpp and AMplitude.h