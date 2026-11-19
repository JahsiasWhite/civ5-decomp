// c5d-model: Gemini 4 Hydrogen
class Host_008388b0 {
public:
    virtual const int* __thiscall GetKeyPtr();
    // src: GUESS (confidence: high) [0x008388b0]
    bool __thiscall EqualsKey(const int* key);
};

bool Host_008388b0::EqualsKey(const int* key) {
    return *GetKeyPtr() == *key;
}
