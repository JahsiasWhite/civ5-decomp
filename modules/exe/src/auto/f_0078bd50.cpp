// Writes a saved game's header: the magic text a character at a time, version 8,
// then the header's strings, flags, DLC and mod lists and GUIDs.

#include "FDataStream.h"

// src: GUESS (confidence: medium)
extern const char* g_szSaveMagic_00c965d4;

// A DLC package the save was made with: its GUID, then its name.
// src: GUESS (confidence: low)
struct SaveDlcEntry_0078bd50
{
    // src: GUESS (confidence: medium)
    GUID m_kId;
    // src: GUESS (confidence: low)
    char m_szName[0x204];
};

// A mod the save was made with.
// src: GUESS (confidence: low)
struct SaveModEntry_0078bd50
{
    // src: GUESS (confidence: low)
    char m_szId[0x40];
    // src: GUESS (confidence: low)
    char m_aData[0x204];
};

// src: GUESS (confidence: low)
enum SaveHeaderEnum_0078bd50
{
};

// src: GUESS (confidence: medium) [0x005567d0]
FDataStream& operator<<(FDataStream& kStream, const SaveDlcEntry_0078bd50& kEntry);
// src: GUESS (confidence: medium) [0x00559870]
FDataStream& operator<<(FDataStream& kStream, const SaveModEntry_0078bd50& kEntry);
// src: GUESS (confidence: medium) [0x0052fa40]
FDataStream& operator<<(FDataStream& kStream, const SaveHeaderEnum_0078bd50& eValue);

// src: GUESS (confidence: medium)
class SaveHeader_0078bd50
{
public:
    // src: GUESS (confidence: medium) [0x0078bd50]
    bool Write(FDataStream& kStream);

    // src: GUESS (confidence: low)
    int m_field00;
    // src: GUESS (confidence: low)
    unsigned int m_uiField04;
    // src: GUESS (confidence: low)
    bool m_bField08;
    // src: GUESS (confidence: low)
    FStringA m_str0C;
    // src: GUESS (confidence: low)
    FStringA m_str10;
    // src: GUESS (confidence: low)
    FStringA m_str14;
    // src: GUESS (confidence: low)
    FStringA m_str18;
    // src: GUESS (confidence: low)
    FStringA m_str1C;
    // src: GUESS (confidence: low)
    FStringA m_str20;
    // src: GUESS (confidence: low)
    FStringA m_str24;
    // src: GUESS (confidence: low)
    FStringA m_str28;
    // src: GUESS (confidence: low)
    FStringA m_str2C;
    // src: GUESS (confidence: low)
    FStringA m_str30;
    // src: GUESS (confidence: low)
    FStringA m_str34;
    // src: GUESS (confidence: low)
    FStringA m_str38;
    // src: GUESS (confidence: low)
    GUID m_kGuid3C;
    // src: GUESS (confidence: low)
    FStringA m_str4C;
    // src: GUESS (confidence: low)
    GUID m_kGuid50;
    // src: GUESS (confidence: low)
    SaveHeaderEnum_0078bd50 m_e60;
    // src: GUESS (confidence: medium)
    std::vector<SaveDlcEntry_0078bd50> m_aDlc;
    // src: GUESS (confidence: medium)
    std::vector<SaveModEntry_0078bd50> m_aMods;
};

bool SaveHeader_0078bd50::Write(FDataStream& kStream)
{
    for (unsigned int i = 0; i < strlen(g_szSaveMagic_00c965d4); ++i)
        kStream << g_szSaveMagic_00c965d4[i];

    kStream << (unsigned int)8;
    kStream << m_str0C;
    kStream << m_str10;
    kStream << m_uiField04;
    kStream << m_bField08;
    kStream << m_str14;
    kStream << m_str18;
    kStream << m_str20;
    kStream << m_str1C;
    kStream << m_str24;
    kStream << m_str28;
    kStream << m_str2C;
    kStream << m_aDlc;
    kStream << m_aMods;
    kStream << m_str30;
    kStream << m_str34;
    kStream << m_str38;
    kStream << m_kGuid3C;
    kStream << m_str4C;
    kStream << m_kGuid50;
    kStream << m_e60;
    return true;
}
