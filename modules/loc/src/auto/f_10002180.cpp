// src: EXE [0x10002180]
#define CVLOCALIZATION_API __declspec(dllexport)
#include "Localization/LocalizationAPI.h"

namespace Localization {

// src: EXE
class ILocalizationLogger;

// src: GUESS (confidence: medium)
class ILogger_100021b0 {
public:
    virtual ~ILogger_100021b0() {}
    virtual void LogMessage(const char* szMessage, int iLevel) = 0;
};

// src: GUESS (confidence: low)
extern ILogger_100021b0* g_pLogger_100c5b1c;

CVLOCALIZATION_API void SetLogger(ILocalizationLogger* pkLogger) {
    if (g_pLogger_100c5b1c != 0) {
        delete g_pLogger_100c5b1c;
    }
    g_pLogger_100c5b1c = 0;
    if (pkLogger != 0) {
        g_pLogger_100c5b1c = (ILogger_100021b0*)pkLogger;
    }
}

}  // namespace Localization
