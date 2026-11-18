#include "Unk_0086c330.h"

// Rightmost node of the subtree rooted at node.
UnkTreeNode_0086c330* TreeMax_0086c330(UnkTreeNode_0086c330* node)
{
    while (!node->m_right->m_isNil)
        node = node->m_right;
    return node;
}
