// src: GUESS 0x0096b490 (confidence: medium)
unsigned __int64 DivUint64Parts_0096b490(unsigned int hi, unsigned int lo, unsigned int divisor) {
    unsigned __int64 dividend = ((unsigned __int64)hi << 32) | lo;
    return dividend / divisor;
}
