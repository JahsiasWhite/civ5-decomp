// c5d-cflags: -/O2 +/O1 +/Oy- +/hotpatch
extern "C" void __cdecl free(void* p);

// src: GUESS (confidence: low)
class Buffer_00927728 {
public:
    // src: GUESS (confidence: low)
    void* m_data;
    // src: GUESS (confidence: low)
    int m_size;
    // src: GUESS (confidence: low)
    int m_capacity;

    // src: GUESS 0x00927728 (confidence: high)
    void Clear();
};

void Buffer_00927728::Clear() {
    if (m_data) {
        free(m_data);
        m_data = 0;
    }
    m_size = 0;
    m_capacity = 0;
}
