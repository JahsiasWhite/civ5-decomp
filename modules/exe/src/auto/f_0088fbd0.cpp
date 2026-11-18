#include "Unk_0088fbd0.h"

// Rightmost node of the subtree rooted at node.
UnkTreeNode_0088fbd0* TreeMax_0088fbd0(UnkTreeNode_0088fbd0* node)
{
    while (!node->m_right->m_isNil)
        node = node->m_right;
    return node;
}
