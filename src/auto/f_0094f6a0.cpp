// Returns the field at offset 0x10 of the given record.

// src: GUESS (confidence: low)
struct Record_0094f6a0
{
    char m_pad[0x10];
    // src: GUESS (confidence: low)
    int m_field10;
};

// src: GUESS (confidence: low) [0x0094f6a0]
int GetField10_0094f6a0(const Record_0094f6a0* record)
{
    return record->m_field10;
}
