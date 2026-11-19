#include "Unk_00746c90.h"

// Rightmost node of the subtree rooted at node.
UnkTreeNode_00746c90* TreeMax_00746c90(UnkTreeNode_00746c90* node)
{
    while (!node->m_right->m_isNil)
        node = node->m_right;
    return node;
}
