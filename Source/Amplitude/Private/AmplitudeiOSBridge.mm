#if PLATFORM_APPLE
/*
The "bridge" class. All methods should defer to respective methods of objc file MyClass
Maybe could use some helper functions
*/
#import "Amplitude.h" // iOS header
#import "AmplitudeiOSBridge.h" // bridge header
#import <Foundation/Foundation.h>
#include <string>

namespace ios_bridge {

  // struct AmplitudeImpl
  // {
  //   Amplitude *wrapped;
  // };

  // Amplitude::Amplitude() :
  // impl(new AmplitudeiOSBridge())
  // {
    // [[Amplitude instance] initializeApiKey:@"bf4d2fcdda37e4ceb78bdde77ac3b153"];
    // impl->wrapped = [[Amplitude alloc] init];
  // }


  NSString* convert(const std::string& str)
  {
    return [NSString stringWithUTF8String:str.c_str()];
  }

    // void initializeApiKey(std::string& apiKey)
    // {
    //   [::Amplitude initializeApiKey:convert(apiKey)];
    // }

  void AmplitudeiOSBridge::initializeApiKey(const std::string& apiKey)
  {
    [[Amplitude instance] initializeApiKey:convert(apiKey)];
  }

  void AmplitudeiOSBridge::initializeApiKey(const std::string& apiKey, const std::string& userId)
  {
    [[Amplitude instance] initializeApiKey:convert(apiKey) userId:convert(userId)];
  }

  void AmplitudeiOSBridge::setLibrary(const std::string& libraryName)
  {
    [Amplitude instance].libraryName = convert(libraryName);
  }

  void AmplitudeiOSBridge::logEvent(const std::string& eventName)
  {
    [[Amplitude instance] logEvent:convert(eventName)];
  }
    // void logEvent()
    // {

    // }
    // static Amplitude instance()
    // {

    // }
}
#endif
