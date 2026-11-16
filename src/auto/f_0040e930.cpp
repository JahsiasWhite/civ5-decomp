// Sets one indexed entry of an object that keeps 64 float values plus a
// 64-bit mask of per-entry flags: stores the value and replaces the entry's
// flag bit with the given state.

class IndexedFloatFlags
{
public:
    void SetEntry(int index, bool flag, float value);

private:
    char m_header[0x40];
    float m_values[64];
    unsigned __int64 m_flags;
};

void IndexedFloatFlags::SetEntry(int index, bool flag, float value)
{
    m_flags &= ~((unsigned __int64)1 << index);
    m_flags |= (__int64)flag << index;
    m_values[index] = value;
}
