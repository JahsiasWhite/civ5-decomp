// src: GUESS (confidence: high) [0x00564f40]
struct TreeNode_00564f40 {
    TreeNode_00564f40* _Left;
    TreeNode_00564f40* _Parent;
    TreeNode_00564f40* _Right;
    unsigned char _Pad[0x95];
    bool _Isnil;
};

// src: GUESS (confidence: high) [0x00564f40]
struct Tree_00564f40 {
    void* _Pad;
    TreeNode_00564f40* _Myhead;

    void _Lrotate(TreeNode_00564f40* _Wherenode);
};

// src: LIB (confidence: high) [0x00564f40]
void Tree_00564f40::_Lrotate(TreeNode_00564f40* _Wherenode) {
    TreeNode_00564f40* _Pnode = _Wherenode->_Right;
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
