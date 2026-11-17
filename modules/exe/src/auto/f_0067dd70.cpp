// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct Elem_0067dd70 {
    char data[0x1c];
};

// src: GUESS (confidence: high)
class VecOwner_0067dd70 {
public:
    int GetCount() const;
    int m_pad0;
    Elem_0067dd70* m_begin;
    Elem_0067dd70* m_end;
};

// src: GUESS (confidence: high) [0x0067dd70]
int VecOwner_0067dd70::GetCount() const {
    return m_end - m_begin;
}
