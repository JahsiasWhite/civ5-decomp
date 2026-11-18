// Describes the sync check for logging: the player, the city and the
// archived size.

#include <stdio.h>

// src: GUESS (confidence: low)
class SyncArchive_00778c10
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
class NetMessageBase_00778c10
{
public:
    virtual void v00();
    // src: GUESS (confidence: low)
    virtual void Describe(char* buffer, unsigned int bufferSize);

    char m_pad4[0x30 - 4];
    // src: GUESS (confidence: low)
    int m_player;
    // src: GUESS (confidence: low)
    int m_city;
};

// src: EXE
class NetCitySyncCheck : public NetMessageBase_00778c10, public SyncArchive_00778c10
{
public:
    // src: GUESS (confidence: low) [0x00778c10]
    virtual void Describe(char* buffer, unsigned int bufferSize);
};

void NetCitySyncCheck::Describe(char* buffer, unsigned int bufferSize)
{
    sprintf_s(buffer, bufferSize, "NetCitySyncCheck(Player=%d, City=%d, ArchiveDataSize=%u)", m_player, m_city, GetDataSize());
}
