// src: GUESS (confidence: low)
struct Elem68_006afdb0
{
    int m_pad00[15];
    int m_id;
    int m_pad40;
};

// src: GUESS (confidence: low)
struct Table_006afdb0
{
    Elem68_006afdb0* m_data;
    unsigned int m_count;

    // src: GUESS (confidence: high) [0x006afdb0]
    Elem68_006afdb0* FindOrFirst(int id);
};

Elem68_006afdb0* Table_006afdb0::FindOrFirst(int id)
{
    for (unsigned int i = 0; i < m_count; ++i)
    {
        if (m_data[i].m_id == id)
        {
            return &m_data[i];
        }
    }
    return m_data;
}
