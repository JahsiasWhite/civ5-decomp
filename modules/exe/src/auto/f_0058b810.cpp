// src: GUESS (confidence: high) [0x0058b810]
struct TreeNode_0058b810 {
    TreeNode_0058b810* _Left;
    TreeNode_0058b810* _Parent;
    TreeNode_0058b810* _Right;
    unsigned char _Pad[0xc5];
    bool _Isnil;
};

// src: GUESS (confidence: high) [0x0058b810]
struct Tree_0058b810 {
    void* _Pad;
    TreeNode_0058b810* _Myhead;

    void _Lrotate(TreeNode_0058b810* _Wherenode);
};

// src: LIB (confidence: high) [0x0058b810]
void Tree_0058b810::_Lrotate(TreeNode_0058b810* _Wherenode) {
    TreeNode_0058b810* _Pnode = _Wherenode->_Right;
    _Wherenode->_Right = _Pnode->_Left;
    if (!_Pnode->_Left->_Isnil) {
        _Pnode->_Left->_Parent = _Wherenode;
    }
    _Pnode->_Parent = _Wherenode->_Parent;
    if (_Wherenode == _Myhead->_Parent) {
        _Myhead->_Parent = _Pnode;
    } else if (_Wherenode == _Wherenode->_Parent->_Left) {
        _Wherenode->_Parent->_Left = _Pnode;
    } else {
        _Wherenode->_Parent->_Right = _Pnode;
    }
    _Pnode->_Left = _Wherenode;
    _Wherenode->_Parent = _Pnode;
}
