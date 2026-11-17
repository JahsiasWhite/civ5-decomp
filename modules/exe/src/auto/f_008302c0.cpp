// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
class Base_008302c0 {
public:
    virtual void v0();
    int m_val;
    Base_008302c0(const Base_008302c0& o) : m_val(o.m_val) {}
};

class Derived_008302c0 : public Base_008302c0 {
public:
    // src: GUESS (confidence: high) [0x008302c0]
    Derived_008302c0(const Derived_008302c0& o);
};

Derived_008302c0::Derived_008302c0(const Derived_008302c0& o)
    : Base_008302c0(o) {
}
