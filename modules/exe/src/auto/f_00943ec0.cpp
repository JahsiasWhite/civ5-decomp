// Returns the field at offset 0x04 of the given record.

// src: GUESS (confidence: low)
struct Record_00943ec0
{
    int m_field00;
    // src: GUESS (confidence: low)
    int m_field04;
};

// src: GUESS (confidence: low) [0x00943ec0]
int GetField04_00943ec0(const Record_00943ec0* record)
{
    return record->m_field04;
}
