// c5d-cflags: -/arch:SSE2
// Reads the next 36-byte record from the buffer. The cursor always
// advances; the result says whether there was room for it.

// src: GUESS (confidence: low)
struct Record36_00630d00
{
    int m_data[9];
};

// src: GUESS (confidence: low)
class Reader_00630d00
{
public:
    // src: GUESS (confidence: low) [0x00630d00]
    bool ReadRecord(Record36_00630d00* out);

    char m_pad0[0x10264];
    // src: GUESS (confidence: low)
    char* m_end;
    // src: GUESS (confidence: low)
    char* m_cursor;
};

bool Reader_00630d00::ReadRecord(Record36_00630d00* out)
{
    bool ok = false;
    if (m_cursor + sizeof(Record36_00630d00) <= m_end)
    {
        *out = *(Record36_00630d00*)m_cursor;
        ok = true;
    }
    m_cursor += sizeof(Record36_00630d00);
    return ok;
}
