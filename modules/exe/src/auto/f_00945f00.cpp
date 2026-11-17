// Returns the field at offset 0x40 of the given record.

// src: GUESS (confidence: low)
struct Record_00945f00
{
    char m_pad[0x40];
    // src: GUESS (confidence: low)
    int m_field40;
};

// src: GUESS (confidence: low) [0x00945f00]
int GetField40_00945f00(const Record_00945f00* record)
{
    return record->m_field40;
}
