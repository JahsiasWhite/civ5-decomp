// c5d-model: Gemini 4 Hydrogen
struct Item8_008ed3c0 {
    char data[8];
};
class Class_008ed3c0 {
public:
    char pad[0x80];
    Item8_008ed3c0* m_arr;
    // src: GUESS (confidence: high) [0x008ed3c0]
    Item8_008ed3c0* __thiscall GetItem(int idx);
};
Item8_008ed3c0* Class_008ed3c0::GetItem(int idx) {
    return &m_arr[idx];
}
