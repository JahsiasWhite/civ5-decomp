// src: EXE [0x10071650]
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>

// src: GUESS (confidence: low)
bool __stdcall ReadFileToBuffer_10071650(
    const wchar_t* wszPath, void** ppBuffer, unsigned int* pCapacity, unsigned int* pOutSize) {
    HANDLE hFile = CreateFileW(
        wszPath, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, 0);
    if (hFile == INVALID_HANDLE_VALUE) {
        return false;
    }
    *pOutSize = 0;
    LARGE_INTEGER liSize;
    if (!GetFileSizeEx(hFile, &liSize) || liSize.HighPart != 0) {
        CloseHandle(hFile);
        return false;
    }
    unsigned int uiNeeded = liSize.LowPart + 1;
    *pOutSize = uiNeeded;
    if (*pCapacity < uiNeeded) {
        void* pNew = realloc(*ppBuffer, uiNeeded);
        if (pNew == 0) {
            CloseHandle(hFile);
            return false;
        }
        *ppBuffer = pNew;
        *pCapacity = *pOutSize;
    }
    if (*ppBuffer == 0) {
        *pCapacity = 0;
        CloseHandle(hFile);
        return false;
    }
    DWORD dwRead = 0;
    ReadFile(hFile, *ppBuffer, *pOutSize, &dwRead, 0);
    ((char*)(*ppBuffer))[dwRead] = 0;
    CloseHandle(hFile);
    return true;
}
