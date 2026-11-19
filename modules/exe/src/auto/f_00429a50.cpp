// Returns the "net_connection_debug.log" log while logging is on; null otherwise.

// src: GUESS (confidence: low)
class FILogFile;

// src: SDK
class FLogFileMgr
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    // src: SDK
    virtual FILogFile* GetLog(const char* name, int flags, int unknown);
    virtual void v04();
    virtual void v05();
    virtual void v06();
    // src: GUESS (confidence: low)
    virtual bool IsLogging();
};

extern "C" FLogFileMgr* s_pLogFileMgr;

// src: GUESS (confidence: low) [0x007ecc20]
FILogFile* GetLog_007ecc20()
{
    FLogFileMgr* mgr = s_pLogFileMgr;
    if (mgr && mgr->IsLogging())
        return mgr->GetLog("net_connection_debug.log", 0, 0);
    return 0;
}
