// src: GUESS (confidence: medium)
bool EncodeUtf8_10008c60(char*& dst, unsigned int cp) {
    if (cp < 0x80) {
        *dst++ = (char)cp;
    } else if (cp < 0x800) {
        dst[1] = (char)((cp & 0x3f) | 0x80);
        cp >>= 6;
        dst[0] = (char)(cp | 0xc0);
        dst += 2;
    } else if (cp < 0x10000) {
        dst[2] = (char)((cp & 0x3f) | 0x80);
        cp >>= 6;
        dst[1] = (char)((cp & 0x3f) | 0x80);
        cp >>= 6;
        dst[0] = (char)(cp | 0xe0);
        dst += 3;
    } else if (cp < 0x110000) {
        dst[3] = (char)((cp & 0x3f) | 0x80);
        cp >>= 6;
        dst[2] = (char)((cp & 0x3f) | 0x80);
        cp >>= 6;
        dst[1] = (char)((cp & 0x3f) | 0x80);
        cp >>= 6;
        dst[0] = (char)(cp | 0xf0);
        dst += 4;
    } else {
        return false;
    }
    return true;
}
