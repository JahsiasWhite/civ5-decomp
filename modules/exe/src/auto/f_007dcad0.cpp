// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct Elem_0044f2f0 {
    char data[0x38];
};

// src: GUESS (confidence: high)
class VecOwner_0044f2f0 {
public:
    int GetCount() const;
    int m_pad0;
    Elem_0044f2f0* m_begin;
    Elem_0044f2f0* m_end;
};

// src: GUESS (confidence: high) [0x0044f2f0]
int VecOwner_0044f2f0::GetCount() const {
    return m_end - m_begin;
}
