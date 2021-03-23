#if PLATFORM_APPLE
#pragma once

/*
The "bridge" class. All methods should defer to respective methods of objc file MyClass
Maybe could use some helper functions
*/
#include <string>
#include <utility>
#include <vector>
namespace ios_bridge
{

  class AmplitudeiOSBridge
  {
  public:
    void initializeApiKey(const std::string &apiKey);
    void initializeApiKey(const std::string &apiKey, const std::string &userId);

    void logEvent(const std::string &eventType);
    void logEvent(const std::string &eventType, const std::vector<std::pair<std::string, std::string>> &propertyPairs);
    void setUserProperty(const std::string &propertyName, std::string &propertyValue);
    void setUserProperties(const std::vector<std::pair<std::string, std::string>> &propertyPairs);

    std::string getUserId();
    void setUserId(const std::string &userId);

    long getSessionId();
    void setSessionId(const long &sessionId);

    void setLibrary(const std::string &libraryName);
    void uploadEvents();
  };
}
#endif
