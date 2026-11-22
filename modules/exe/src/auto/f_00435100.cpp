// src: GUESS (confidence: high) [0x00435100]
struct TreeNode_00435100 {
    TreeNode_00435100* _Left;
    TreeNode_00435100* _Parent;
    TreeNode_00435100* _Right;
    unsigned char _Pad[0x09];
    bool _Isnil;
};

// src: GUESS (confidence: high) [0x00435100]
struct Tree_00435100 {
    void* _Pad;
    TreeNode_00435100* _Myhead;

    void _Rrotate(TreeNode_00435100* _Wherenode);
};

// src: LIB (confidence: high) [0x00435100]
void Tree_00435100::_Rrotate(TreeNode_00435100* _Wherenode) {
    TreeNode_00435100* _Pnode = _Wherenode->_Left;
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
