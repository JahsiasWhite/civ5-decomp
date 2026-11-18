// src: GUESS (confidence: low)
struct Obj_10001450 {
    // src: GUESS (confidence: low)
    virtual ~Obj_10001450() {}
};

// src: GUESS (confidence: low)
class Owner_10001450 {
public:
    // src: GUESS 0x10001450 (confidence: high)
    void Set(Obj_10001450* ptr);

private:
    // src: GUESS (confidence: low)
    Obj_10001450* m_ptr;
};

void Owner_10001450::Set(Obj_10001450* ptr) {
    if (ptr != m_ptr && m_ptr != 0) {
        delete m_ptr;
    }
    m_ptr = ptr;
}
