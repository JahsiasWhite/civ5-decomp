// src: GUESS (confidence: low) [0x00658f70]
struct Class_00658f70 {
    char pad[5];
    unsigned char count;
    char pad2[0x20 - 6];
    short items[50];

    int Add(short val);
};

int Class_00658f70::Add(short val) {
    if (this->count < 0x32) {
        this->items[this->count] = val;
        ++this->count;
        return (int)this->count - 1;
    }
    return -1;
}
