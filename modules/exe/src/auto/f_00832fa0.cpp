// Records a reference on the current entry and appends the pair to the
// two parallel lists.

// src: GUESS (confidence: low)
struct Entry_008ccf20
{
    char m_pad0[0x54];
    // src: GUESS (confidence: low)
    int m_refs;
    char m_pad58[0x80 - 0x58];
};

// src: GUESS (confidence: low)
class Builder_008ccf20
{
public:
    // src: GUESS (confidence: low) [0x008ccf20]
    void Add(int a, int b);

    int& CurrentRefs() { return m_entries[m_current].m_refs; }

    // src: GUESS (confidence: low)
    Entry_008ccf20* m_entries;
    // src: GUESS (confidence: low)
    int m_current;
    char m_pad8[0x54 - 8];
    // src: GUESS (confidence: low)
    int m_count;
    // src: GUESS (confidence: low)
    int* m_firsts;
    // src: GUESS (confidence: low)
    int* m_seconds;
};

void Builder_008ccf20::Add(int a, int b)
{
    ++CurrentRefs();
    m_firsts[m_count] = a;
    m_seconds[m_count] = b;
    ++m_count;
}
