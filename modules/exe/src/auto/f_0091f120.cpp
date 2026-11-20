// src: GUESS (confidence: low)
struct UnkInner_0091f120
{
    int pad[2];
    int m_f08;
    int m_f0c;
    int m_f10;
};

// src: GUESS (confidence: low)
struct UnkOuter_0091f120
{
    int pad[4];
    UnkInner_0091f120* m_p10;
};

// src: GUESS (confidence: medium) [0x0091f120]
int GetFlags_0091f120(UnkOuter_0091f120* obj)
{
    int ret = 0;
    UnkInner_0091f120* inner = obj->m_p10;
    if (inner)
    {
        if (inner->m_f08)
            ret = 4;
        else if (inner->m_f10)
            ret = 2;
    }
    return ret;
}
