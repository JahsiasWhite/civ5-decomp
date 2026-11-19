#include "Unk_00455410.h"

// Rightmost node of the subtree rooted at node.
UnkTreeNode_00455410* TreeMax_00455410(UnkTreeNode_00455410* node)
{
    while (!node->m_right->m_isNil)
        node = node->m_right;
    return node;
}
