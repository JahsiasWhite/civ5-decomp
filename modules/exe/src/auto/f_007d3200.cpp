// c5d-cflags: -/arch:SSE2
// Once the given turn reaches the pending one, resets the view (virtual
// slot 39, with 10) and clears the pending turn.

// src: GUESS (confidence: low)
class View_006812e0
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
    virtual void v36();
    virtual void v37();
    virtual void v38();
    // src: GUESS (confidence: low)
    virtual void SetZoom(float zoom);
};

// src: GUESS (confidence: low)
class Scheduler_006812e0
{
public:
    // src: GUESS (confidence: low) [0x006812e0]
    void Update(int turn);

    // src: GUESS (confidence: low)
    View_006812e0* m_view;
    char m_pad4[0x110 - 4];
    // src: GUESS (confidence: low)
    int m_pendingTurn;
};

void Scheduler_006812e0::Update(int turn)
{
    if (m_pendingTurn >= 0 && turn >= m_pendingTurn)
    {
        m_view->SetZoom(10.0f);
        m_pendingTurn = -1;
    }
}
