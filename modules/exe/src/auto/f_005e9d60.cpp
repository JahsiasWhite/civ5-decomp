// Clears the first field of every active 24-byte entry in a global table,
// last to first, then marks the table as reset.

// src: GUESS (confidence: low)
struct Entry_0079e630
{
    // src: GUESS (confidence: low)
    int m_value;
    int m_rest[5];
};

// src: GUESS (confidence: low) [0x01a0c7c8]
extern int g_entryCount_01a0c7c8;
// src: GUESS (confidence: low) [0x01a0c7d8]
extern Entry_0079e630 g_entries_01a0c7d8[];
// src: GUESS (confidence: low) [0x01a0c77e]
extern bool g_entriesReset_01a0c77e;

// src: GUESS (confidence: low) [0x0079e630]
void ResetEntries_0079e630()
{
    int i = g_entryCount_01a0c7c8;
    while (i--)
        g_entries_01a0c7d8[i].m_value = 0;
    g_entriesReset_01a0c77e = true;
}
