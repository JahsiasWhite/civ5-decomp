// c5d-cflags: -/EHsc +/GS-   (no unwind table or stack cookie in the original)
// Builds a save's file name: a prefix (AutoSave_ and the like), the name given in
// UTF-8, and the save file extension.

#include "FStringW.h"

// c5d-review: GetSaveFileExtensionAlias is an undefined alias for GetSaveFileExtension
// (0x005c59a0, src/auto/f_005c59a0.cpp). The original reads the converted name before
// the call, as if the call might change it; seeing the body, our /LTCG link moves the
// read after it instead.
// src: GUESS (confidence: medium) [0x005c59a0]
const wchar_t* GetSaveFileExtensionAlias();

// src: GUESS (confidence: low)
class SaveNamer_006336e0
{
public:
    // src: GUESS (confidence: medium) [0x006336e0]
    void MakeSaveFileName(FStringW& kOut, const wchar_t* szPrefix, const char* szName);
};

void SaveNamer_006336e0::MakeSaveFileName(FStringW& kOut, const wchar_t* szPrefix, const char* szName)
{
    FStringW kName;
    FStringFixedBufferW<260> kBuffer(kName);
    kName.SetUTF8(szName);
    const wchar_t* szConverted = kName.c_str();
    kOut.Format(L"%s%s%s", szPrefix, szConverted, GetSaveFileExtensionAlias());
}
