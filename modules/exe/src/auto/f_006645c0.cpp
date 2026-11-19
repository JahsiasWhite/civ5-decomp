// c5d-cflags: -/arch:SSE2
// Reads the next 40-byte record from the buffer. The cursor always
// advances; the result says whether there was room for it.

// src: GUESS (confidence: low)
struct Record40_007a2620
{
    int m_data[10];
};

// src: GUESS (confidence: low)
class Reader_007a2620
{
public:
    // src: GUESS (confidence: low) [0x007a2620]
    bool ReadRecord(Record40_007a2620* out);

    char m_pad0[0x10264];
    // src: GUESS (confidence: low)
    char* m_end;
    // src: GUESS (confidence: low)
    char* m_cursor;
};

bool Reader_007a2620::ReadRecord(Record40_007a2620* out)
{
    bool ok = false;
    if (m_cursor + sizeof(Record40_007a2620) <= m_end)
    {
        *out = *(Record40_007a2620*)m_cursor;
        ok = true;
    }
    m_cursor += sizeof(Record40_007a2620);
    return ok;
}
