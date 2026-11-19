#include "Unk_007b9ca0.h"

// Rightmost node of the subtree rooted at node.
UnkTreeNode* TreeMax_007b9ca0(UnkTreeNode* node) {
    while (!node->m_right->m_isNil)
        node = node->m_right;
    return node;
}
