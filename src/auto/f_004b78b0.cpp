// Red-black tree helper: from a node, follows left children down to the
// leftmost real node (the one whose left child is the nil sentinel).

struct TreeNode_004b78b0
{
    TreeNode_004b78b0* left;
    char pad04[0xa1 - 4];
    bool isNil;                 // +0xa1
};

TreeNode_004b78b0* TreeMinNode(TreeNode_004b78b0* node)
{
    while (!node->left->isNil)
        node = node->left;
    return node;
}
