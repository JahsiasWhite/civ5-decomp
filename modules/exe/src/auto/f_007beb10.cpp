// Describes the sync check for logging: the player and the archived size.

#include <stdio.h>

// src: GUESS (confidence: low)
class SyncArchive_00582d00
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
class NetMessageBase_00582d00
{
public:
    virtual void v00();
    // src: GUESS (confidence: low)
    virtual void Describe(char* buffer, unsigned int bufferSize);

    char m_pad4[0x30 - 4];
    // src: GUESS (confidence: low)
    int m_player;
};

// src: EXE [0x00a90858]
class NetPlayerSyncCheck : public NetMessageBase_00582d00, public SyncArchive_00582d00
{
public:
    // src: GUESS (confidence: low) [0x00582d00]
    virtual void Describe(char* buffer, unsigned int bufferSize);
};

void NetPlayerSyncCheck::Describe(char* buffer, unsigned int bufferSize)
{
    sprintf_s(buffer, bufferSize, "NetPlayerSyncCheck(Player=%d), ArchiveDataSize=%u", m_player, GetDataSize());
}
