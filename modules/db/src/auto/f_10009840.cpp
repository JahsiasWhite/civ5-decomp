// src: GUESS (confidence: low) [0x10008a00]
bool CompareBytes_10008a00(const unsigned char* a, unsigned int lenA, const unsigned char* b, unsigned int lenB, bool caseSensitive);

// src: GUESS (confidence: low) [0x1061b6e4]
extern const unsigned char g_empty_1061b6e4[];

// src: GUESS (confidence: low)
struct XmlAttr_10009840
{
    const unsigned char* m_name;
    int m_pad04;
    unsigned int m_nameLen;
    int m_pad0c[3];
    XmlAttr_10009840* m_next18;
    int m_pad1c;
    XmlAttr_10009840* m_firstAttr20;

    // src: GUESS (confidence: high) [0x10009840]
    XmlAttr_10009840* FindAttr(const unsigned char* name, unsigned int len, bool caseSensitive);
};

XmlAttr_10009840* XmlAttr_10009840::FindAttr(const unsigned char* name, unsigned int len, bool caseSensitive)
{
    if (name)
    {
        if (!len)
        {
            const unsigned char* p = name;
            while (*p)
            {
                ++p;
            }
            len = (unsigned int)(p - name);
        }
        for (XmlAttr_10009840* n = m_firstAttr20; n; n = n->m_next18)
        {
            if (CompareBytes_10008a00(n->m_name ? n->m_name : g_empty_1061b6e4, n->m_name ? n->m_nameLen : 0, name, len, caseSensitive))
            {
                return n;
            }
        }
        return 0;
    }
    return m_firstAttr20;
}
