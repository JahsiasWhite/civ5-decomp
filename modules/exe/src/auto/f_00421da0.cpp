// Disconnects: closes the connection when it's in state 3, then destroys
// the owned socket object.

namespace Nexus
{

// src: GUESS (confidence: low)
class Disposable_007d9870
{
public:
    // src: GUESS (confidence: low)
    virtual void Dispose(int flags);
};

// src: GUESS (confidence: low)
class CommunicatorBase_007d9870
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    // src: GUESS (confidence: low)
    virtual void Disconnect();

    // src: GUESS (confidence: low)
    Disposable_007d9870* m_socket;
    char m_pad8[0x20 - 8];
};

// src: GUESS (confidence: low)
class Connection_007d9870
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    // src: GUESS (confidence: low)
    virtual void Close();

    int m_24;
};

// src: EXE [0x00b8583c]
class CommunicatorTCPIP : public CommunicatorBase_007d9870, public Connection_007d9870
{
public:
    // src: GUESS (confidence: low) [0x007d9870]
    virtual void Disconnect();

    // src: GUESS (confidence: low)
    int m_state;
};

void CommunicatorTCPIP::Disconnect()
{
    if (m_state == 3)
        Close();
    if (m_socket)
    {
        m_socket->Dispose(0);
        m_socket = 0;
    }
}

} // namespace Nexus
