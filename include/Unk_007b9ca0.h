#pragma once

// Placeholder: a red-black tree node in the VC9 std::_Tree layout
// (left, parent, right, an 8-byte value, color, nil flag). Rename once the
// owning container's element type is known.

// src: GUESS (confidence: medium) [0x007b9ca0]
struct UnkTreeNode
{
    UnkTreeNode* m_left;     // 0x00
    UnkTreeNode* m_parent;   // 0x04
    UnkTreeNode* m_right;    // 0x08
    int m_value[2];          // 0x0c
    char m_color;            // 0x14
    char m_isNil;            // 0x15
};

// src: GUESS (confidence: medium) [0x007b9ca0]
UnkTreeNode* TreeMax_007b9ca0(UnkTreeNode* node);
