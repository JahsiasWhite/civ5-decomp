// Returns the address of field 0x6c in the current entry of an object's
// array of 0x80-byte entries.

// src: GUESS (confidence: low)
struct Entry_00548910
{
    char m_pad0[0x6c];
    // src: GUESS (confidence: low)
    int m_value;
    char m_pad70[0x10];
};

// src: GUESS (confidence: low)
struct Table_00548910
{
    char m_pad0[0xb0];
    // src: GUESS (confidence: low)
    Entry_00548910* m_entries;
    int m_padb4;
    // src: GUESS (confidence: low)
    int m_current;
};

// src: GUESS (confidence: low) [0x00548910]
int* __stdcall GetCurrentEntryValue(Table_00548910* table)
{
    return &table->m_entries[table->m_current].m_value;
}
