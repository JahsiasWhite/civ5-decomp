#pragma once

// Placeholder: a cursor over linked nodes. The node it points at (0x04) links
// to others at 0x10, 0x18, 0x20 and 0x2c; each step method moves another cursor
// to one of them. Rename once the node type is known (the links look like
// parent/sibling/child pointers).

// src: GUESS (confidence: low) [0x0082d030]
struct UnkNode_0082d030
{
    int m_unk00[4];
    UnkNode_0082d030* m_link10;     // 0x10
    int m_unk14;
    UnkNode_0082d030* m_next;       // 0x18
    int m_unk1c;
    UnkNode_0082d030* m_first;      // 0x20
    int m_unk24[2];
    UnkNode_0082d030* m_link2c;     // 0x2c
};

// src: GUESS (confidence: low) [0x0082d030]
class UnkNodeCursor_0082d030
{
public:
    // src: GUESS (confidence: low) [0x0082d030]
    int CountChildren();
    // src: GUESS (confidence: low) [0x0082d050]
    bool GetFirst(UnkNodeCursor_0082d030* out);
    // src: GUESS (confidence: low) [0x0082d0b0]
    bool GetLink10(UnkNodeCursor_0082d030* out);
    // src: GUESS (confidence: low) [0x0082d0f0]
    bool GetNext(UnkNodeCursor_0082d030* out);
    // src: GUESS (confidence: low) [0x0082d150]
    bool GetLink2c(UnkNodeCursor_0082d030* out);

    int m_unk00;
    UnkNode_0082d030* m_node;   // 0x04
};
