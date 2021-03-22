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

  NSMutableDictionary* convert(const std::vector<std::pair<std::string, std::string>> &propertyPairs)
  {
    NSMutableDictionary* userProperties = [NSMutableDictionary dictionary];
    for (const auto& propValuePair: propertyPairs) {
     [userProperties  setValue:convert(propValuePair.second) forKey:convert(propValuePair.first)];
    }

    return userProperties;
  }

  void AmplitudeiOSBridge::initializeApiKey(const std::string& apiKey)
  {
    [[Amplitude instance] initializeApiKey:convert(apiKey)];
  }

  void AmplitudeiOSBridge::initializeApiKey(const std::string& apiKey, const std::string& userId)
  {
    [[Amplitude instance] initializeApiKey:convert(apiKey) userId:convert(userId)];
  }


  void AmplitudeiOSBridge::logEvent(const std::string& eventType)
  {
    [[Amplitude instance] logEvent:convert(eventType)];
  }

  void AmplitudeiOSBridge::logEvent(const std::string &eventType, const std::vector<std::pair<std::string, std::string>> &propertyPairs)
  {
    NSMutableDictionary *eventProperties = convert(propertyPairs);
    [[Amplitude instance] logEvent:convert(eventType) withEventProperties:eventProperties];
  }

  void AmplitudeiOSBridge::setUserProperties(const std::vector<std::pair<std::string, std::string>> &propertyPairs)
  {
    NSMutableDictionary *userProperties = convert(propertyPairs);
    [[Amplitude instance] setUserProperties:userProperties];
  }

  void AmplitudeiOSBridge::setUserProperty(const std::string &propertyName, std::string &propertyValue)
  {
    std::vector<std::pair<std::string, std::string>> propertyPairs;
    std::pair <std::string,std::string> propertyPair (propertyName, propertyValue);
    propertyPairs.push_back(propertyPair);
    setUserProperties(propertyPairs);
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
