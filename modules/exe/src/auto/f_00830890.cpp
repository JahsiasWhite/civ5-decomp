// CRC-32 update over a byte buffer using the object's 256-entry table.

// src: GUESS (confidence: low)
class Crc32_00830890
{
public:
    // src: GUESS (confidence: low) [0x00830890]
    unsigned int Update(const unsigned char* data, unsigned int length, unsigned int crc) const;

    // src: GUESS (confidence: low)
    unsigned int m_table[256];
};

unsigned int Crc32_00830890::Update(const unsigned char* data, unsigned int length, unsigned int crc) const
{
    const unsigned char* p = data;
    while (length)
    {
        crc = m_table[(*p ^ crc) & 0xff] ^ (crc >> 8);
        --length;
        ++p;
    }
    return crc;
}
