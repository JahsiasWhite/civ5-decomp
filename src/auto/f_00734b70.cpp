// c5d-model: claude-opus-5-5
// Leftmost-node walk of a red-black tree whose nodes carry a large payload
// (the _Isnil flag sits at offset 0xd1). Equivalent to std::_Tree::_Min.

struct TreeNode_00734b70
{
    TreeNode_00734b70* left;
    char pad[0xd1 - sizeof(TreeNode_00734b70*)];
    char isNil;
};

TreeNode_00734b70* TreeMin_00734b70(TreeNode_00734b70* node)
{
    while (!node->left->isNil)
        node = node->left;
    return node;
}
