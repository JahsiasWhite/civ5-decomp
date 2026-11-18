#pragma once

// Placeholder: a red-black tree node in the VC9 std::_Tree layout (left, parent,
// right, a 0x94-byte value, color, nil flag). Rename once the element type is known.

// src: GUESS (confidence: medium) [0x0076cb40]
struct UnkTreeNode_0076cb40
{
    UnkTreeNode_0076cb40* m_left;
    UnkTreeNode_0076cb40* m_parent;
    UnkTreeNode_0076cb40* m_right;
    int m_value[37];
    char m_color;
    char m_isNil;
};

// src: GUESS (confidence: medium) [0x0076cb40]
UnkTreeNode_0076cb40* TreeMax_0076cb40(UnkTreeNode_0076cb40* node);
