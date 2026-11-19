// Tests one bit of a growable bit array; bits outside it read as clear.

// src: GUESS (confidence: low)
struct BitArray_009449d0
{
    // src: GUESS (confidence: low)
    unsigned int* m_words;
    // src: GUESS (confidence: low)
    int m_wordCount;
};

// src: GUESS (confidence: low) [0x009449d0]
int TestBit_009449d0(const BitArray_009449d0* bits, int bit)
{
    if (bit < 0)
        return 0;
    int word = bit / 32;
    if (bits->m_wordCount <= word)
        return 0;
    return (bits->m_words[word] >> (bit % 32)) & 1;
}
