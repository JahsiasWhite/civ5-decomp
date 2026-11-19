// src: GUESS (confidence: low) [0x10008a00]
bool CompareBytes_10008a00(const unsigned char* a, unsigned int lenA, const unsigned char* b, unsigned int lenB, bool caseSensitive);

// src: GUESS (confidence: low) [0x1061b6e4]
extern const unsigned char g_empty_1061b6e4[];

// src: GUESS (confidence: low)
struct XmlNode_1000a5f0
{
    const unsigned char* m_name;
    int m_pad04;
    unsigned int m_nameLen;
    int m_pad0c[3];
    XmlNode_1000a5f0* m_firstChild18;
    int m_pad1c[4];
    XmlNode_1000a5f0* m_next2c;

    // src: GUESS (confidence: high) [0x1000a5f0]
    XmlNode_1000a5f0* FindFirstChild(const unsigned char* name, unsigned int len, bool caseSensitive);
};

XmlNode_1000a5f0* XmlNode_1000a5f0::FindFirstChild(const unsigned char* name, unsigned int len, bool caseSensitive)
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
        for (XmlNode_1000a5f0* n = m_firstChild18; n; n = n->m_next2c)
        {
            if (CompareBytes_10008a00(n->m_name ? n->m_name : g_empty_1061b6e4, n->m_name ? n->m_nameLen : 0, name, len, caseSensitive))
            {
                return n;
            }
        }
        return 0;
    }
    return m_firstChild18;
}
