// src: GUESS (confidence: low)
class Lexer_00476980 {
public:
    // src: GUESS (confidence: low) [0x00476980]
    bool IsDelimiterOrQuote();

private:
    const char* m_pBuf;
    const char* m_pDelims;
    int m_iPos;
    bool m_bSkipDelims;
};

bool Lexer_00476980::IsDelimiterOrQuote()
{
    int ch = m_pBuf[m_iPos];
    if (!m_bSkipDelims) {
        int len = *(const int*)(m_pDelims - 8);
        for (int i = 0; i < len; ++i) {
            if ((int)m_pDelims[i] == ch) {
                return true;
            }
        }
    }
    return ch == '"';
}
