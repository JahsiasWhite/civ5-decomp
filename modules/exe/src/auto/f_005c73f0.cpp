// src: GUESS (confidence: low) [0x005c73f0]
int f_005c73f0(unsigned char c) {
    switch (c) {
    case 1:
    case 3:
    case 5:
    case 6:
    case 7:
        return 0;
    case 2:
        return 1;
    case 4:
        return 2;
    case 8:
        return 3;
    default:
        return 0;
    }
}
