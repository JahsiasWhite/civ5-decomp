// Returns the field at offset 0x58 of the given record.

// src: GUESS (confidence: low)
struct Record_00945ef0
{
    char m_pad[0x58];
    // src: GUESS (confidence: low)
    int m_field58;
};

// src: GUESS (confidence: low) [0x00945ef0]
int GetField58_00945ef0(const Record_00945ef0* record)
{
    return record->m_field58;
}
