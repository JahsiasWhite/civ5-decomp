// c5d-cflags: -/Ob1 +/Ob0
#include <string>

// src: GUESS (confidence: low)
struct UnkStrHolder_006c8f80
{
    std::string m_str;

    bool IsEmpty_006c8f80();
};

// src: GUESS (confidence: medium) [0x006c8f80]
bool UnkStrHolder_006c8f80::IsEmpty_006c8f80()
{
    return m_str.empty() || m_str.c_str() == 0;
}
