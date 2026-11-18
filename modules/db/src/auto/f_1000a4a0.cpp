// src: GUESS (confidence: low)
struct Node_1000a4a0 {
    char m_pad[0x20];
    // src: GUESS (confidence: low)
    void* m_ptr;
};

// src: GUESS (confidence: low)
struct Handle_1000a4a0 {
    int m_pad00;
    // src: GUESS (confidence: low)
    void* m_ptr;
};

// src: GUESS (confidence: low)
class Cursor_1000a4a0 {
public:
    // src: GUESS 0x1000a4a0 (confidence: high)
    bool Step20(Handle_1000a4a0* out);

private:
    int m_pad00;
    // src: GUESS (confidence: low)
    Node_1000a4a0* m_node;
};

bool Cursor_1000a4a0::Step20(Handle_1000a4a0* out) {
    if (m_node != 0) {
        void* next = m_node->m_ptr;
        if (next != 0) {
            out->m_ptr = next;
            return true;
        }
    }
    return false;
}
