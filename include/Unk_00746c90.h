#pragma once

// Placeholder: a red-black tree node in the VC9 std::_Tree layout (left, parent,
// right, a 0xc4-byte value, color, nil flag). Rename once the element type is known.

// src: GUESS (confidence: medium) [0x00746c90]
struct UnkTreeNode_00746c90
{
    UnkTreeNode_00746c90* m_left;
    UnkTreeNode_00746c90* m_parent;
    UnkTreeNode_00746c90* m_right;
    int m_value[49];
    char m_color;
    char m_isNil;
};

// src: GUESS (confidence: medium) [0x00746c90]
UnkTreeNode_00746c90* TreeMax_00746c90(UnkTreeNode_00746c90* node);
