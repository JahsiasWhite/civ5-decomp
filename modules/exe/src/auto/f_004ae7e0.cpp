// Appends a 0x60-byte message of type 0x71 to the queue's current buffer and gives it
// the next serial number. The queue's lock is taken and left held for the caller.

#include <vector>
#include "FCriticalSection.h"

// src: GUESS (confidence: low)
struct MessageHeader_005d9d50
{
    MessageHeader_005d9d50(int size, int type)
        : m_size(size), m_type(type), m_field08(0), m_field0C(0)
    {
    }

    // src: GUESS (confidence: medium)
    int m_size;
    // src: GUESS (confidence: medium)
    int m_type;
    // src: GUESS (confidence: low)
    int m_field08;
    // src: GUESS (confidence: low)
    int m_field0C;
};

// src: GUESS (confidence: low)
struct MessageBody71_005d9d50
{
    MessageBody71_005d9d50()
        : m_field00(-1), m_field04(-1), m_field08(-1), m_field0C(0),
          m_field10(-1), m_field14(0), m_field18(-1), m_field1C(0),
          m_field20(-1), m_field24(0), m_field28(0), m_field2C(0), m_field30(0)
    {
    }

    // src: GUESS (confidence: low)
    int m_field00;
    // src: GUESS (confidence: low)
    int m_field04;
    // src: GUESS (confidence: low)
    int m_field08;
    // src: GUESS (confidence: low)
    int m_field0C;
    // src: GUESS (confidence: low)
    int m_field10;
    // src: GUESS (confidence: low)
    int m_field14;
    // src: GUESS (confidence: low)
    int m_field18;
    // src: GUESS (confidence: low)
    int m_field1C;
    // src: GUESS (confidence: low)
    int m_field20;
    // src: GUESS (confidence: low)
    int m_field24;
    // src: GUESS (confidence: low)
    int m_field28;
    // src: GUESS (confidence: low)
    int m_field2C;
    // src: GUESS (confidence: low)
    int m_field30;
};

// src: GUESS (confidence: low)
class MessageQueue_005d9d50
{
public:
    // src: GUESS (confidence: low) [0x005d9d50]
    long* PushMessage71();

    // src: GUESS (confidence: medium)
    std::vector<char> m_buffers[2];
    // src: GUESS (confidence: medium)
    unsigned int m_current;
    // src: GUESS (confidence: low)
    int m_field24;
    // src: GUESS (confidence: medium)
    long m_serial;
    // src: GUESS (confidence: low)
    char m_pad2C[8];
    // src: GUESS (confidence: medium)
    FCriticalSection m_lock;
};

long* MessageQueue_005d9d50::PushMessage71()
{
    m_lock.Enter();
    std::vector<char>& buffer = m_buffers[m_current & 1];
    size_t offset = buffer.size();
    buffer.insert(buffer.begin() + offset, 0x60, char(0));
    char* message = &buffer[0] + offset;
    new (message) MessageHeader_005d9d50(0x60, 0x71);
    new (message + 0x10) MessageBody71_005d9d50();
    long* serial = new (message + 0x44) long(0);
    *serial = InterlockedIncrement(&m_serial);
    return serial;
}
