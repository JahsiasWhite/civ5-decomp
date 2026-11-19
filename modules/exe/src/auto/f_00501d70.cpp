// src: GUESS (confidence: low)
struct Unk_005e8c60
{
    int m_type;
    int m_f04;
    int m_f08;
    int m_f0c;

    // src: GUESS (confidence: high) [0x005e8c60]
    int** GetPtr(int** out);
};

int** Unk_005e8c60::GetPtr(int** out)
{
    switch (m_type)
    {
    case 0:
        *out = (int*)m_f04;
        break;
    case 1:
        *out = (int*)m_f08;
        break;
    case 2:
        *out = &m_f0c;
        break;
    default:
        *out = (int*)m_f04;
        break;
    }
    return out;
}
