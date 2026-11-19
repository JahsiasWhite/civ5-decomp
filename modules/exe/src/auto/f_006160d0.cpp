// Returns the 32-byte info for the entry with the given id; the first info
// when there's no such entry.

// src: GUESS (confidence: low)
struct Entry_0075f080
{
    char m_pad0[0x3c];
    // src: GUESS (confidence: low)
    int m_id;
    int m_40;
};

// src: GUESS (confidence: low)
struct Info_0075f080
{
    int m_data[8];
};

// src: GUESS (confidence: low)
class Registry_0075f080
{
public:
    // src: GUESS (confidence: low) [0x0075f080]
    Info_0075f080* GetInfo(int id) const;

    // src: GUESS (confidence: low)
    Entry_0075f080* m_entries;
    // src: GUESS (confidence: low)
    unsigned int m_count;
    int m_08;
    // src: GUESS (confidence: low)
    Info_0075f080* m_infos;
};

Info_0075f080* Registry_0075f080::GetInfo(int id) const
{
    for (unsigned int i = 0; i < m_count; ++i)
    {
        if (m_entries[i].m_id == id)
            return &m_infos[i];
    }
    return m_infos;
}
