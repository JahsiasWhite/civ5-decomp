// c5d-model: Gemini 4 Hydrogen
struct Item12_00627a00 {
    char data[12];
};
class Class_00627a00 {
public:
    Item12_00627a00* m_arr;
    // src: GUESS (confidence: high) [0x00627a00]
    Item12_00627a00* __thiscall GetItem(int idx);
};
Item12_00627a00* Class_00627a00::GetItem(int idx) {
    return &m_arr[idx];
}
