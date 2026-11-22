// src: GUESS (confidence: low) [0x00885d10]
struct Item_00885d10 {
    char m_flag; // src: GUESS (confidence: low) [0x00885d10]
    char pad1[0x24b]; // src: GUESS (confidence: low) [0x00885d10]
};

struct Auto_00885d10 {
    char pad0[0x10]; // src: GUESS (confidence: low) [0x00885d10]
    int m_count; // src: GUESS (confidence: low) [0x00885d10]
    char pad14[0x4c]; // src: GUESS (confidence: low) [0x00885d10]
    Item_00885d10* m_items; // src: GUESS (confidence: low) [0x00885d10]

    int f_00885d10(); // src: GUESS (confidence: low) [0x00885d10]
};

int Auto_00885d10::f_00885d10() {
    for (int i = 0; i < m_count; ++i) {
        if (m_items[i].m_flag != 0) {
            return i;
        }
    }
    return -1;
}
