#if PLATFORM_APPLE
#pragma once

/*
The "bridge" class. All methods should defer to respective methods of objc file MyClass
Maybe could use some helper functions
*/
#include <string>

namespace ios_bridge
{
  // struct AmplitudeImpl;

  class AmplitudeiOSBridge
  {
  public:
    // AmplitudeiOSBridge(const std::string s);
    // ~AmplitudeiOSBridge();
    void initializeApiKey(const std::string &eventName);
    void initializeApiKey(const std::string &eventName, const std::string &userId);
    void logEvent(const std::string &eventName);
    void setUserId(const std::string &userId);
    std::string getUserId();
    void setLibrary(const std::string &libraryName);
    // AmplitudeiOSBridge instance();
    // NSString* convert(const std::string s)
    // void testEventSend();
    // private:
    // AmplitudeImpl *impl;
  };
}
#endif
