// Returns the field at offset 0x14 of the given record.

// src: GUESS (confidence: low)
struct Record_00942c70
{
    char m_pad[0x14];
    // src: GUESS (confidence: low)
    int m_field14;
};

// src: GUESS (confidence: low) [0x00942c70]
int GetField14_00942c70(const Record_00942c70* record)
{
    return record->m_field14;
}
