// Reads the next 2-byte value from the buffer. The cursor always advances;
// the result says whether there was room for it.

// src: GUESS (confidence: low)
class Reader_005bf510
{
public:
    // src: GUESS (confidence: low) [0x005bf510]
    bool ReadShort(short* out);

    char m_pad0[0x10264];
    // src: GUESS (confidence: low)
    char* m_end;
    // src: GUESS (confidence: low)
    char* m_cursor;
};

bool Reader_005bf510::ReadShort(short* out)
{
    bool ok = false;
    if (m_cursor + sizeof(short) <= m_end)
    {
        *out = *(short*)m_cursor;
        ok = true;
    }
    m_cursor += sizeof(short);
    return ok;
}
