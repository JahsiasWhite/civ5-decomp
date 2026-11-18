#pragma once

// Placeholder: a red-black tree node in the VC9 std::_Tree layout (left, parent,
// right, a 0x108-byte value, color, nil flag). Rename once the element type is known.

// src: GUESS (confidence: medium) [0x00455410]
struct UnkTreeNode_00455410
{
    UnkTreeNode_00455410* m_left;
    UnkTreeNode_00455410* m_parent;
    UnkTreeNode_00455410* m_right;
    int m_value[0x42];
    char m_color;
    char m_isNil;
};

// src: GUESS (confidence: medium) [0x00455410]
UnkTreeNode_00455410* TreeMax_00455410(UnkTreeNode_00455410* node);
