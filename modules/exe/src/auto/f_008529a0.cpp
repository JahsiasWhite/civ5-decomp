#include "Unk_008ecf10.h"

// The record at index, or null when it's out of range.
UnkRecord3C_008ecf10* UnkRecordArray_008ecf10::GetRecord(unsigned int index)
{
    if (index < m_count)
        return &m_records[index];
    return 0;
}
