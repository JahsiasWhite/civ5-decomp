// c5d-model: claude-opus-5-5
// FJobSet C entry points exported for the gameplay DLL.
#include <stddef.h>

class FJobSetImpl
{
public:
    void Wait();                            // 0x0081d790
};

void AddJobToSet(void* pJob, FJobSetImpl* pSet, void* pUserData, int iFlags);   // 0x0081d950

// 0x0081d660, 15 bytes
extern "C" void FJobSetInitImpl(FJobSetImpl** ppImpl)
{
    if (ppImpl)
        *ppImpl = NULL;
}

// 0x0081d6a0, 9 bytes
extern "C" void FJobSetWaitImpl(FJobSetImpl* pImpl)
{
    pImpl->Wait();
}

// 0x0081d6b0, 26 bytes
extern "C" void FJobSetAddJobImpl(FJobSetImpl* pSet, void* pJob, void* pUserData)
{
    AddJobToSet(pJob, pSet, pUserData, 0);
}
