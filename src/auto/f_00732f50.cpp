// c5d-model: claude-opus-5-5
// Returns the address of one record in an inline array of large
// (0x2d60-byte) records owned by the object.

struct LargeRecord_00732f50
{
    char data[0x2d60];
};

class LargeRecordTable
{
public:
    LargeRecord_00732f50* GetRecord(int index);

private:
    char m_header[0x280];
    LargeRecord_00732f50 m_records[1];
};

LargeRecord_00732f50* LargeRecordTable::GetRecord(int index)
{
    return &m_records[index];
}
