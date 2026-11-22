// src: GUESS (confidence: high) [0x00785f10]
struct TreeNode_00785f10 {
    TreeNode_00785f10* _Left;
    TreeNode_00785f10* _Parent;
    TreeNode_00785f10* _Right;
    unsigned char _Pad[0x109];
    bool _Isnil;
};

// src: GUESS (confidence: high) [0x00785f10]
struct Tree_00785f10 {
    void* _Pad;
    TreeNode_00785f10* _Myhead;

    void _Lrotate(TreeNode_00785f10* _Wherenode);
};

// src: LIB (confidence: high) [0x00785f10]
void Tree_00785f10::_Lrotate(TreeNode_00785f10* _Wherenode) {
    TreeNode_00785f10* _Pnode = _Wherenode->_Right;
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
