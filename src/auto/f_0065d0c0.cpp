// c5d-model: Gemini 4 Hydrogen
struct Item76_0065d0c0 {
    char data[0x4c];
};
class Class_0065d0c0 {
public:
    char pad[0x40c20];
    Item76_0065d0c0* m_arr;
    // src: GUESS (confidence: high) [0x0065d0c0]
    Item76_0065d0c0* __thiscall GetItem(int idx);
};
Item76_0065d0c0* Class_0065d0c0::GetItem(int idx) {
    return &m_arr[idx];
}
