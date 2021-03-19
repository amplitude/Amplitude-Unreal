#if PLATFORM_APPLE
/*
The "bridge" class. All methods should defer to respective methods of objc file MyClass
Maybe could use some helper functions
*/
#import "AmplitudeiOSBridge.h" // bridge header
#import "Amplitude.h" // iOS header
#import <Foundation/Foundation.h>
#include <string>

namespace ios_bridge {

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

  void AmplitudeiOSBridge::logEvent(const std::string& eventName)
  {
    [[Amplitude instance] logEvent:convert(eventName)];
  }

  std::string AmplitudeiOSBridge::getUserId()
  {
    NSString* userId = [Amplitude instance].userId;
    return std::string([userId UTF8String]);
  }

  void AmplitudeiOSBridge::setUserId(const std::string& userId)
  {
    [[Amplitude instance] setUserId:convert(userId)];
  }

  long AmplitudeiOSBridge::getSessionId()
  {
    return [[Amplitude instance] getSessionId];
  }

  void AmplitudeiOSBridge::setSessionId(const long& sessionId)
  {
    [[Amplitude instance] setSessionId:sessionId];
  }


  void AmplitudeiOSBridge::setLibrary(const std::string& libraryName)
  {
    [Amplitude instance].libraryName = convert(libraryName);
  }

  void AmplitudeiOSBridge::uploadEvents()
  {
    [[Amplitude instance] uploadEvents];
  }
}
#endif
