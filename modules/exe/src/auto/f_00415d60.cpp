// Reads the next 4-byte int from the buffer. The cursor always advances; the
// result says whether there was room for a whole int.

// src: GUESS (confidence: low)
class Reader_00415d60
{
public:
    // src: GUESS (confidence: low) [0x00415d60]
    bool ReadInt(int* out);

    char m_pad0[0x10264];
    // src: GUESS (confidence: low)
    char* m_end;
    // src: GUESS (confidence: low)
    char* m_cursor;
};

bool Reader_00415d60::ReadInt(int* out)
{
    bool ok = false;
    if (m_cursor + sizeof(int) <= m_end)
    {
        *out = *(int*)m_cursor;
        ok = true;
    }
    m_cursor += sizeof(int);
    return ok;
}
