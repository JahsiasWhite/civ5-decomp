// src: GUESS (confidence: high) [0x0046a8b0]
struct TreeNode_0046a8b0 {
    TreeNode_0046a8b0* _Left;
    TreeNode_0046a8b0* _Parent;
    TreeNode_0046a8b0* _Right;
    unsigned char _Pad[0x05];
    bool _Isnil;
};

// src: GUESS (confidence: high) [0x0046a8b0]
struct Tree_0046a8b0 {
    void* _Pad;
    TreeNode_0046a8b0* _Myhead;

    void _Rrotate(TreeNode_0046a8b0* _Wherenode);
};

// src: LIB (confidence: high) [0x0046a8b0]
void Tree_0046a8b0::_Rrotate(TreeNode_0046a8b0* _Wherenode) {
    TreeNode_0046a8b0* _Pnode = _Wherenode->_Left;
    _Wherenode->_Left = _Pnode->_Right;
    if (!_Pnode->_Right->_Isnil) {
        _Pnode->_Right->_Parent = _Wherenode;
    }
    _Pnode->_Parent = _Wherenode->_Parent;
    if (_Wherenode == _Myhead->_Parent) {
        _Myhead->_Parent = _Pnode;
    } else if (_Wherenode == _Wherenode->_Parent->_Right) {
        _Wherenode->_Parent->_Right = _Pnode;
    } else {
        _Wherenode->_Parent->_Left = _Pnode;
    }
    _Pnode->_Right = _Wherenode;
    _Wherenode->_Parent = _Pnode;
}
