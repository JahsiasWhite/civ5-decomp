// Resets the level to zero and tells every child of the attached node to do the same.

#include <vector>

// src: GUESS (confidence: low)
class Child_004fdf50
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    // src: GUESS (confidence: low)
    virtual void SetValue(int kind, float value);
};

// src: GUESS (confidence: low)
struct Node_004fdf50
{
    char m_pad0[0x4c];
    // src: GUESS (confidence: low)
    std::vector<Child_004fdf50*> m_children;
};

// src: GUESS (confidence: low)
struct Owner_004fdf50
{
    // src: GUESS (confidence: low) [0x004fdf50]
    void ResetLevel();

    char m_pad0[0x94];
    // src: GUESS (confidence: low)
    Node_004fdf50* m_node;
    char m_pad98[0xf0 - 0x98];
    // src: GUESS (confidence: low)
    float m_level;
};

void Owner_004fdf50::ResetLevel()
{
    Node_004fdf50* node = m_node;
    if (node)
    {
        m_level = 0.0f;
        for (std::vector<Child_004fdf50*>::iterator it = node->m_children.begin(); it != node->m_children.end(); ++it)
        {
            (*it)->SetValue(4, 0.0f);
        }
    }
}
