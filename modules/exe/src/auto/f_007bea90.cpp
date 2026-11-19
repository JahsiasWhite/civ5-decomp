// Describes the sync check for logging: the player, the unit and the
// archived size.

#include <stdio.h>

// src: GUESS (confidence: low)
class SyncArchive_00636130
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    // src: GUESS (confidence: low)
    virtual unsigned int GetDataSize();
};

// src: GUESS (confidence: low)
class NetMessageBase_00636130
{
public:
    virtual void v00();
    // src: GUESS (confidence: low)
    virtual void Describe(char* buffer, unsigned int bufferSize);

    char m_pad4[0x30 - 4];
    // src: GUESS (confidence: low)
    int m_player;
    // src: GUESS (confidence: low)
    int m_unit;
};

// src: EXE
class NetUnitSyncCheck : public NetMessageBase_00636130, public SyncArchive_00636130
{
public:
    // src: GUESS (confidence: low) [0x00636130]
    virtual void Describe(char* buffer, unsigned int bufferSize);
};

void NetUnitSyncCheck::Describe(char* buffer, unsigned int bufferSize)
{
    sprintf_s(buffer, bufferSize, "NetUnitSyncCheck(Player=%d, Unit=%d, ArchiveDataSize=%u)", m_player, m_unit, GetDataSize());
}
