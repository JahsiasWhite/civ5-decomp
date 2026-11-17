// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct Elem_00419780 {
    char data[0x214];
};

// src: GUESS (confidence: high)
class VecOwner_00419780 {
public:
    int GetCount() const;
    int m_pad0;
    Elem_00419780* m_begin;
    Elem_00419780* m_end;
};

// src: GUESS (confidence: high) [0x00419780]
int VecOwner_00419780::GetCount() const {
    return m_end - m_begin;
}
