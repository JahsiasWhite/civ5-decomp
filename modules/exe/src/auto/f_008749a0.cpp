// When flag 8 is set, reports this object's id and kind, with the value, to
// the global manager's handler (virtual slot 36).

// src: GUESS (confidence: low)
class Handler_0090e9c0
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    // src: GUESS (confidence: low)
    virtual void Report(int id, int kind, int value);
};

// src: GUESS (confidence: low)
struct Manager_0090e9c0
{
    char m_pad0[0x9c];
    // src: GUESS (confidence: low)
    Handler_0090e9c0* m_handler;
};

// src: GUESS (confidence: low) [0x0606baf0]
extern Manager_0090e9c0* g_manager_0606baf0;

// src: GUESS (confidence: low)
class Reporter_0090e9c0
{
public:
    // src: GUESS (confidence: low) [0x0090e9c0]
    void Report(int value);

    int m_00;
    // src: GUESS (confidence: low)
    int m_id;
    char m_pad8[0x14 - 8];
    // src: GUESS (confidence: low)
    int m_kind;
    // src: GUESS (confidence: low)
    unsigned int m_flags;
};

void Reporter_0090e9c0::Report(int value)
{
    if (m_flags & 8)
        g_manager_0606baf0->m_handler->Report(m_id, m_kind, value);
}
