// src: GUESS (confidence: low)
struct Streambuf_0047da00 {
    __declspec(dllimport) void _Lock();
};

// src: GUESS (confidence: low)
struct Ostream_0047da00;

// src: GUESS (confidence: low)
struct IosBase_0047da00 {
    int m_00;
    int m_04;
    int m_state;
    char m_0c[0x1c];
    Streambuf_0047da00* m_rdbuf;
    Ostream_0047da00* m_tie;
};

// src: GUESS (confidence: low)
struct Ostream_0047da00 : virtual public IosBase_0047da00 {
    __declspec(dllimport) Ostream_0047da00& flush();
};

// src: GUESS (confidence: low)
struct Sentry_0047da00 {
    Ostream_0047da00* m_ostr;
    bool m_ok;

    Sentry_0047da00(Ostream_0047da00& ostr);
};

// src: LIB [0x0047da00]
Sentry_0047da00::Sentry_0047da00(Ostream_0047da00& ostr)
    : m_ostr(&ostr) {
    if (ostr.m_rdbuf != 0) {
        ostr.m_rdbuf->_Lock();
    }
    if (ostr.m_state == 0 && ostr.m_tie != 0) {
        ostr.m_tie->flush();
    }
    m_ok = (ostr.m_state == 0);
}
