// The engine utility interface the game core is handed. Only the first slots are
// declared so far; order follows the SDK.
#pragma once

#include "ICvEngineScriptSystem1.h"

// src: SDK
class ICvEngineUtility1
{
public:
    // src: SDK
    virtual void* QueryInterface(int guidInterface) = 0;
    // src: SDK
    virtual void Destroy() = 0;
    // src: SDK
    virtual void* getInterfaceIFace() = 0;
    // src: SDK
    virtual ICvEngineScriptSystem1* GetScriptSystem() = 0;
};
