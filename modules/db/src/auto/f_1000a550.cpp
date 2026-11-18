// src: GUESS (confidence: low)
struct Node_1000a550 {
    char m_pad[0x2c];
    // src: GUESS (confidence: low)
    void* m_ptr;
};

// src: GUESS (confidence: low)
struct Handle_1000a550 {
    int m_pad00;
    // src: GUESS (confidence: low)
    void* m_ptr;
};

// src: GUESS (confidence: low)
class Cursor_1000a550 {
public:
    // src: GUESS 0x1000a550 (confidence: high)
    bool Step2C(Handle_1000a550* out);

private:
    int m_pad00;
    // src: GUESS (confidence: low)
    Node_1000a550* m_node;
};

bool Cursor_1000a550::Step2C(Handle_1000a550* out) {
    if (m_node != 0) {
        void* next = m_node->m_ptr;
        if (next != 0) {
            out->m_ptr = next;
            return true;
        }
    }
    return false;
}
