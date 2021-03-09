#if PLATFORM_APPLE
/*
The "bridge" class. All methods should defer to respective methods of objc file MyClass
Maybe could use some helper functions
*/
#import "AmplitudeiOSBridge.h" // bridge header
// #import "Amplitude.h" // iOS header
#import "AmplitudeIOS/include/Amplitude.h"
#import <Foundation/Foundation.h>
#include <string>

namespace ios_bridge {

  // struct AmplitudeImpl
  // {
  //   Amplitude *wrapped;
  // };

  NSString* convert(const std::string& str)
  {
    return [NSString stringWithUTF8String:str.c_str()];
  }

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

  void AmplitudeiOSBridge::setUserId(const std::string& userId)
  {
    [[Amplitude instance] setUserId:convert(userId)];
  }

  std::string AmplitudeiOSBridge::getUserId()
  {
    NSString* userId = [[Amplitude instance] getUserId:convert(userId)];
    return std::string([userId UTF8String]);
  }
}
#endif
