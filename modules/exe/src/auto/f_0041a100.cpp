// c5d-cflags: +/Oy-
// src: GUESS (confidence: high) [0x0041a100]
struct TreeNode_0041a100 {
    TreeNode_0041a100* _Left;
    TreeNode_0041a100* _Parent;
    TreeNode_0041a100* _Right;
    unsigned char _Pad[0x39];
    bool _Isnil;

    void _Lrotate(TreeNode_0041a100** _Myhead_ptr);
};

// src: LIB (confidence: high) [0x0041a100]
void TreeNode_0041a100::_Lrotate(TreeNode_0041a100** _Myhead_ptr) {
    TreeNode_0041a100* _Pnode = this->_Right;
    this->_Right = _Pnode->_Left;
    if (!_Pnode->_Left->_Isnil) {
        _Pnode->_Left->_Parent = this;
    }
    _Pnode->_Parent = this->_Parent;
    if (this == _Myhead_ptr[1]->_Parent) {
        _Myhead_ptr[1]->_Parent = _Pnode;
    } else if (this == this->_Parent->_Left) {
        this->_Parent->_Left = _Pnode;
    } else {
        this->_Parent->_Right = _Pnode;
    }
    _Pnode->_Left = this;
    this->_Parent = _Pnode;
}
