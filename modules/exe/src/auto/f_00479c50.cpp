// Finds the first child of the owner's root whose state is 1; on success
// stores it in the result.

// src: GUESS (confidence: low)
struct Child_0082c630
{
    char m_pad0[0x14];
    // src: GUESS (confidence: low)
    int m_state;
    char m_pad18[0x2c - 0x18];
    // src: GUESS (confidence: low)
    Child_0082c630* m_next;
};

// src: GUESS (confidence: low)
struct Root_0082c630
{
    char m_pad0[0x18];
    // src: GUESS (confidence: low)
    Child_0082c630* m_firstChild;
};

// src: GUESS (confidence: low)
struct Result_0082c630
{
    int m_00;
    // src: GUESS (confidence: low)
    Child_0082c630* m_child;
};

// src: GUESS (confidence: low)
class Finder_0082c630
{
public:
    // src: GUESS (confidence: low) [0x0082c630]
    bool FindActive(Result_0082c630* result) const;

    int m_00;
    int m_04;
    // src: GUESS (confidence: low)
    Root_0082c630* m_root;
};

bool Finder_0082c630::FindActive(Result_0082c630* result) const
{
    if (m_root)
    {
        for (Child_0082c630* child = m_root->m_firstChild; child; child = child->m_next)
        {
            if (child->m_state == 1)
            {
                result->m_child = child;
                return true;
            }
        }
    }
    return false;
}
