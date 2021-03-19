#if PLATFORM_APPLE
/*
The "bridge" class. All methods should defer to respective methods of objc file MyClass
Maybe could use some helper functions
*/
#import "AmplitudeiOSBridge.h" // bridge header
#import "Amplitude.h" // iOS header
#import <Foundation/Foundation.h>
#include <string>
#include <utility>
#include <vector>

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

  void AmplitudeiOSBridge::setLibrary(const std::string& libraryName)
  {
    [Amplitude instance].libraryName = convert(libraryName);
  }

  void AmplitudeiOSBridge::logEvent(const std::string& eventType)
  {
    [[Amplitude instance] logEvent:convert(eventType)];
  }

  void AmplitudeiOSBridge::logEvent(const std::string &eventType, const std::vector<std::pair<std::string, std::string>> &propertyPairs)
  {
    NSMutableDictionary *eventProperties = [NSMutableDictionary dictionary];
    // Range based for
    for(const auto& propValuePair: propertyPairs) {
     [eventProperties setValue:convert(propValuePair.first) forKey:convert(propValuePair.second)];
    }
    [[Amplitude instance] logEvent:convert(eventType) withEventProperties:eventProperties];
  }

  void AmplitudeiOSBridge::setUserId(const std::string& userId)
  {
    [[Amplitude instance] setUserId:convert(userId)];
  }

  std::string AmplitudeiOSBridge::getUserId()
  {
    NSString* userId = [Amplitude instance].userId;
    return std::string([userId UTF8String]);
  }
}
#endif
