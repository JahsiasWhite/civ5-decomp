// Returns the field at offset 0x08 of the given record.

// src: GUESS (confidence: low)
struct Record_00943f00
{
    char m_pad[0x08];
    // src: GUESS (confidence: low)
    int m_field08;
};

// src: GUESS (confidence: low) [0x00943f00]
int GetField08_00943f00(const Record_00943f00* record)
{
    return record->m_field08;
}
