// Reads a 64-byte character array from a stream, one byte at a time.

// src: GUESS (confidence: low)
class ByteStream_0077bf50
{
public:
    virtual void v00();
    // src: GUESS (confidence: low)
    virtual void Read(int count, char* dest);
};

// src: GUESS (confidence: low) [0x0077bf50]
ByteStream_0077bf50& operator>>(ByteStream_0077bf50& stream, char (&buffer)[64])
{
    for (unsigned int i = 0; i < 64; ++i)
        stream.Read(1, &buffer[i]);
    return stream;
}
