// Small engine exports used by the gameplay DLL.
#include <stddef.h>
#include <malloc.h>

struct FStringInitData { int _data[4]; };
struct FTempHeap { int _data[1]; };
class FLogFileMgr;
class FMemTracker;

static FStringInitData s_FStringAInitData;   // 0x06196a1c
static FStringInitData s_FStringWInitData;   // 0x06196a2c
static FLogFileMgr*    s_pLogFileMgr;        // 0x06196a54
static FTempHeap       s_TempHeap;           // 0x06196d70

FMemTracker* GetMemTracker();                // 0x00824750

// 0x00813f70, 6 bytes
extern "C" FStringInitData* FStringA_GetStringInitData()
{
    return &s_FStringAInitData;
}

// 0x00815f10, 6 bytes
extern "C" FStringInitData* FStringW_GetStringInitData()
{
    return &s_FStringWInitData;
}

// 0x0081cd50, 6 bytes
extern "C" FLogFileMgr* PeekLogFileMgr()
{
    return s_pLogFileMgr;
}

// 0x00829aa0, 6 bytes
extern "C" FTempHeap* GetTempHeap()
{
    return &s_TempHeap;
}

// 0x00824800, 18 bytes
extern "C" FMemTracker* GetMemTrackerForDLL()
{
    if (_get_heap_handle())
        return GetMemTracker();
    return NULL;
}
