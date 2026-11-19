#include "Unk_0076cb40.h"

// Rightmost node of the subtree rooted at node.
UnkTreeNode_0076cb40* TreeMax_0076cb40(UnkTreeNode_0076cb40* node)
{
    while (!node->m_right->m_isNil)
        node = node->m_right;
    return node;
}
