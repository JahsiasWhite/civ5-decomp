// Returns whether the index field at offset 0x4c is valid (not -1).

// src: GUESS (confidence: low)
class IndexOwner_005eb560
{
public:
    // src: GUESS (confidence: low) [0x005eb560]
    bool HasIndex4c() const;

    char m_pad[0x4c];
    // src: GUESS (confidence: low)
    int m_index4c;
};

bool IndexOwner_005eb560::HasIndex4c() const
{
    return m_index4c != -1;
}
