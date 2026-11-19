// Closes the socket, if open, and tells the listener the connection is
// closed.

#include <winsock2.h>

// src: GUESS (confidence: low)
class Listener_007ea8b0
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    // src: GUESS (confidence: low)
    virtual void OnEvent(int id, int event, int a, int b);
};

// src: GUESS (confidence: low) [0x00a91730]
class Socket_007ea8b0
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
    // src: GUESS (confidence: low) [0x007ea8b0]
    virtual void Close();

    // src: GUESS (confidence: low)
    int m_id;
    char m_pad8[0x14 - 8];
    // src: GUESS (confidence: low)
    Listener_007ea8b0* m_listener;
    char m_pad18[0x2c - 0x18];
    // src: GUESS (confidence: low)
    SOCKET m_socket;
};

void Socket_007ea8b0::Close()
{
    if (m_socket != INVALID_SOCKET)
    {
        closesocket(m_socket);
        m_socket = INVALID_SOCKET;
        if (m_listener)
            m_listener->OnEvent(m_id, 2, 0, 0);
    }
}
