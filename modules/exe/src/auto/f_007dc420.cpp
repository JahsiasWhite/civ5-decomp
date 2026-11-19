// Sets the entry's name, id and flag.

#include <string>

// src: GUESS (confidence: low)
class Entry_004d9070
{
public:
    // src: GUESS (confidence: low) [0x004d9070]
    void Set(const char* name, short id, bool flag);

    char m_pad0[0x120];
    // src: GUESS (confidence: low)
    std::string m_name;
    // src: GUESS (confidence: low)
    short m_id;
    // src: GUESS (confidence: low)
    bool m_flag;
};

void Entry_004d9070::Set(const char* name, short id, bool flag)
{
    m_id = id;
    m_name = name;
    m_flag = flag;
}
