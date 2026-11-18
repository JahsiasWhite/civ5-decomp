// FireWorks' wide string. It holds one pointer to its characters, which sit 0x0c
// bytes into a block whose header ends with a "don't free" flag (a short just before
// the characters). An empty string points into the shared init data.
#pragma once

// src: EXE
struct FStringInitData;

// c5d-review: FStringW's members get the init data through GetInitData, an undefined
// alias for FStringW_GetStringInitData (0x00815f10, defined in src/core/CoreExports.cpp).
// The original calls it afresh each time, as a library built without /GL would; seeing
// its body, our /LTCG link reuses the first result instead.

// src: GUESS (confidence: medium) [0x00813d10]
void FStringFree(void* pBlock);

// src: GUESS (confidence: high)
class FStringW
{
public:
    FStringW()
    {
        m_pszData = (wchar_t*)((char*)GetInitData() + 0x0c);
    }

    ~FStringW()
    {
        Header* pBlock = (Header*)m_pszData - 1;
        if (pBlock != 0 && pBlock != (Header*)GetInitData() && pBlock->m_sNoFree == 0)
        {
            FStringFree(pBlock);
        }
        m_pszData = (wchar_t*)((char*)GetInitData() + 0x0c);
    }

    // The block in front of the characters.
    // src: GUESS (confidence: medium)
    struct Header
    {
        // src: GUESS (confidence: medium)
        int m_iCapacity;
        // src: GUESS (confidence: low)
        int m_iLength;
        // src: GUESS (confidence: low)
        short m_sField08;
        // src: GUESS (confidence: medium)
        short m_sNoFree;
    };

    // src: EXE [0x00815f10]
    static FStringInitData* GetInitData();

    const wchar_t* c_str() const { return m_pszData; }

    // src: GUESS (confidence: high) [0x00816f60]
    void SetUTF8(const char* szText);
    // src: GUESS (confidence: high) [0x00816930]
    void Format(const wchar_t* szFormat, ...);

    // src: GUESS (confidence: high)
    wchar_t* m_pszData;
};

// A fixed buffer on the stack that a string uses for its characters, so short strings
// need no allocation. The header matches a heap block's: capacity, then the flag that
// says the block isn't to be freed.
// src: GUESS (confidence: medium)
template <int N>
class FStringFixedBufferW
{
public:
    // src: GUESS (confidence: medium) [0x0072b770 for N = 260]
    FStringFixedBufferW(FStringW& kString);

    // src: GUESS (confidence: medium)
    int m_iCapacity;
    // src: GUESS (confidence: low)
    int m_iLength;
    // src: GUESS (confidence: low)
    short m_sField08;
    // src: GUESS (confidence: medium)
    short m_sNoFree;
    // src: GUESS (confidence: medium)
    wchar_t m_aBuffer[N];
};
