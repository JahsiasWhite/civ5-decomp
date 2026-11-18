// src: GUESS (confidence: low)
struct Node_1000a990 {
    char m_pad[0x18];
    // src: GUESS (confidence: low)
    void* m_ptr;
};

// src: GUESS (confidence: low)
struct Handle_1000a990 {
    int m_pad00;
    // src: GUESS (confidence: low)
    void* m_ptr;
};

// src: GUESS (confidence: low)
class Cursor_1000a990 {
public:
    // src: GUESS 0x1000a990 (confidence: high)
    bool Step18(Handle_1000a990* out);

private:
    int m_pad00;
    // src: GUESS (confidence: low)
    Node_1000a990* m_node;
};

bool Cursor_1000a990::Step18(Handle_1000a990* out) {
    if (m_node != 0) {
        void* next = m_node->m_ptr;
        if (next != 0) {
            out->m_ptr = next;
            return true;
        }
    }
    return false;
}
