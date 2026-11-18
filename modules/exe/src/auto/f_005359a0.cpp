// Reads a 64-byte character array from a stream, one byte at a time.

// src: GUESS (confidence: low)
class ByteStream_005359a0
{
public:
    virtual void v00();
    virtual void v01();
    // src: GUESS (confidence: low)
    virtual void Read(int count, char* dest);
};

// src: GUESS (confidence: low) [0x005359a0]
ByteStream_005359a0& operator>>(ByteStream_005359a0& stream, char (&buffer)[64])
{
    for (unsigned int i = 0; i < 64; ++i)
        stream.Read(1, &buffer[i]);
    return stream;
}
