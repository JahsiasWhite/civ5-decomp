#pragma once

struct UnkRecord30
{
    char m_pad00[0x30];
    int m_data30;

    int GetField30() const;
};
