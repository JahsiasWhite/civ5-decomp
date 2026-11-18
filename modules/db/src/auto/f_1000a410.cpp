// src: GUESS (confidence: low)
struct Node_1000a410 {
    int m_pad00[4];
    // src: GUESS (confidence: low)
    int m_parent10;
    int m_pad14;
    // src: GUESS (confidence: low)
    void* m_next18;
};

// src: GUESS (confidence: low)
struct Handle_1000a410 {
    int m_pad00;
    // src: GUESS (confidence: low)
    void* m_ptr;
};

// src: GUESS (confidence: low)
class Cursor_1000a410 {
public:
    // src: GUESS 0x1000a410 (confidence: high)
    bool NextWithParent(Handle_1000a410* out);

private:
    int m_pad00;
    // src: GUESS (confidence: low)
    Node_1000a410* m_node;
};

bool Cursor_1000a410::NextWithParent(Handle_1000a410* out) {
    Node_1000a410* node = m_node;
    if (node->m_parent10 != 0) {
        void* next = node->m_next18;
        if (next != 0) {
            out->m_ptr = next;
            return true;
        }
    }
    return false;
}
