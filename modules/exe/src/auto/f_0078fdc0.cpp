// src: GUESS (confidence: low) [0x00659a60]
struct Class_00659a60 {
    char pad[4];
    char* start;
    char* end;
    char pad2[4];
    int idx;

    bool Step();
};

bool Class_00659a60::Step() {
    int size = (int)(this->end - this->start) >> 3;
    if (size == 0) {
        return false;
    }
    int cur = this->idx;
    if (cur == 0) {
        this->idx = size - 1;
        return true;
    }
    this->idx = cur - 1;
    return false;
}
