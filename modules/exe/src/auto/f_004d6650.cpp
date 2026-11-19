// Returns whether a 16-bit-character string is empty (its first character is 0).

// src: GUESS (confidence: low)
class WideText_006d54d0
{
public:
    // src: GUESS (confidence: low) [0x006d54d0]
    bool IsEmpty() const;

    // src: GUESS (confidence: low)
    wchar_t m_text[1];
};

bool WideText_006d54d0::IsEmpty() const
{
    return m_text[0] == 0;
}
