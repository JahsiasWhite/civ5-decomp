// src: GUESS (confidence: low) [0x0046b7a0]
struct Class_0046b7a0 {
    char pad[0x2d4c];
    int table[1];

    int GetOrSet(int idx, int val);
};

int Class_0046b7a0::GetOrSet(int idx, int val) {
    if (this->table[idx] == 0) {
        this->table[idx] = val;
    }
    return this->table[idx];
}
