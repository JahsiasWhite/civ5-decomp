// Tests whether the flag bit for a type id (one of 14 known ids) is set.

// src: GUESS (confidence: low) [0x00ba2ff8]
extern int g_flagIds_00ba2ff8[14];

// src: GUESS (confidence: low)
inline int FindFlagIndex_0056c3d0(int id)
{
    for (int i = 0; i < 14; ++i)
    {
        if (g_flagIds_00ba2ff8[i] == id)
        {
            return i;
        }
    }
    return -1;
}

// src: GUESS (confidence: low)
struct FlagSet_0056c3d0
{
    // src: GUESS (confidence: low) [0x0056c3d0]
    bool HasFlag(int id) const;

    char m_pad0[0x64];
    // src: GUESS (confidence: low)
    unsigned int m_flags;
};

bool FlagSet_0056c3d0::HasFlag(int id) const
{
    int index = FindFlagIndex_0056c3d0(id);
    if (index != -1)
    {
        return (m_flags & (1 << index)) != 0;
    }
    return false;
}
