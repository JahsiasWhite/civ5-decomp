// src: GUESS (confidence: low)
struct Node_1000a970 {
    int m_pad00[6];
    // src: GUESS (confidence: low)
    void* m_next18;
};

// src: GUESS (confidence: low)
struct Handle_1000a970 {
    int m_pad00;
    // src: GUESS (confidence: low)
    void* m_ptr;
};

// src: GUESS (confidence: low)
class Cursor_1000a970 {
public:
    // src: GUESS 0x1000a970 (confidence: high)
    bool Step18(Handle_1000a970* out);

private:
    int m_pad00;
    // src: GUESS (confidence: low)
    Node_1000a970* m_node;
};

bool Cursor_1000a970::Step18(Handle_1000a970* out) {
    void* next = m_node->m_next18;
    if (next) {
        out->m_ptr = next;
        return true;
    }
    return false;
}
