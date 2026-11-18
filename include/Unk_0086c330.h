#pragma once

// Placeholder: a red-black tree node in the VC9 std::_Tree layout (left, parent,
// right, a 20-byte value, color, nil flag). Rename once the element type is known.

// src: GUESS (confidence: medium) [0x0086c330]
struct UnkTreeNode_0086c330
{
    UnkTreeNode_0086c330* m_left;
    UnkTreeNode_0086c330* m_parent;
    UnkTreeNode_0086c330* m_right;
    int m_value[5];
    char m_color;
    char m_isNil;
};

// src: GUESS (confidence: medium) [0x0086c330]
UnkTreeNode_0086c330* TreeMax_0086c330(UnkTreeNode_0086c330* node);
