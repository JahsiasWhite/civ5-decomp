// src: GUESS (confidence: low) [0x00444930]
struct Logger444930 {
    virtual void vf00() = 0;
    virtual void vf04() = 0;
    virtual void vf08() = 0;
    virtual void* openLog(const char* name, int a2, int a3) = 0;
    virtual void vf10() = 0;
    virtual void vf14() = 0;
    virtual void vf18() = 0;
    virtual bool isEnabled() = 0;
};

// src: GUESS (confidence: low) [0x00444930]
extern bool g_netDebugEnabled;
// src: GUESS (confidence: low) [0x00444930]
extern Logger444930* g_netLogger;

// src: GUESS (confidence: low) [0x00444930]
void* __cdecl getNetMessageDebugLog() {
    if (g_netDebugEnabled) {
        Logger444930* logger = g_netLogger;
        if (logger && logger->isEnabled()) {
            return logger->openLog("net_message_debug.log", 0, 0);
        }
    }
    return 0;
}
