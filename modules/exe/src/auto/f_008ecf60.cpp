// src: GUESS (confidence: low) [0x008ecf60]
struct Class_008ecf60 {
    char str[0x40];
    int f40;
    Class_008ecf60& operator=(const Class_008ecf60& other);
};
Class_008ecf60& Class_008ecf60::operator=(const Class_008ecf60& other) {
    this->f40 = other.f40;
    const char* s = other.str;
    char* d = this->str;
    char c;
    do {
        c = *s;
        *d = c;
        s++;
        d++;
    } while (c != 0);
    return *this;
}
