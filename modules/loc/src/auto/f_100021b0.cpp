// src: EXE [0x100021b0]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/LocalizationAPI.h"

namespace Localization {

// src: GUESS (confidence: medium)
class ILogger_100021b0 {
public:
    virtual ~ILogger_100021b0() {}
    virtual void LogMessage(const char* szMessage, int iLevel) = 0;
};

// src: GUESS (confidence: low)
extern ILogger_100021b0* g_pLogger_100c5b1c;

CVLOCALIZATION_API void LogMessage(const char* szMessage) {
    if (g_pLogger_100c5b1c != 0) {
        g_pLogger_100c5b1c->LogMessage(szMessage, 0);
    }
}

}  // namespace Localization
