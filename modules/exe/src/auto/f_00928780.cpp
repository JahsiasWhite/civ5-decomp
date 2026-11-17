// Returns the field at offset 0x34 of the given record.

// src: GUESS (confidence: low)
struct Record_00928780
{
    char m_pad[0x34];
    // src: GUESS (confidence: low)
    int m_field34;
};

// src: GUESS (confidence: low) [0x00928780]
int GetField34_00928780(const Record_00928780* record)
{
    return record->m_field34;
}
