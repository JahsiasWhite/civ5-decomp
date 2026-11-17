// Returns the field at offset 0x0c of the given record.

// src: GUESS (confidence: low)
struct Record_00927c40
{
    char m_pad[0x0c];
    // src: GUESS (confidence: low)
    int m_field0c;
};

// src: GUESS (confidence: low) [0x00927c40]
int GetField0C_00927c40(const Record_00927c40* record)
{
    return record->m_field0c;
}
