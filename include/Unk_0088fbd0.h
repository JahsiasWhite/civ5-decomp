#pragma once

// Placeholder: a red-black tree node in the VC9 std::_Tree layout (left, parent,
// right, a 16-byte value, color, nil flag). Rename once the element type is known.

// src: GUESS (confidence: medium) [0x0088fbd0]
struct UnkTreeNode_0088fbd0
{
    UnkTreeNode_0088fbd0* m_left;
    UnkTreeNode_0088fbd0* m_parent;
    UnkTreeNode_0088fbd0* m_right;
    int m_value[4];
    char m_color;
    char m_isNil;
};

// src: GUESS (confidence: medium) [0x0088fbd0]
UnkTreeNode_0088fbd0* TreeMax_0088fbd0(UnkTreeNode_0088fbd0* node);
