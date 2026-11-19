// Switches the socket between blocking and non-blocking mode; 7 on failure.

#include <winsock2.h>

// src: GUESS (confidence: low)
struct Socket_007e5630
{
    // src: GUESS (confidence: low) [0x007e5630]
    int SetBlocking(bool blocking);

    char m_pad0[4];
    // src: GUESS (confidence: low)
    SOCKET m_socket;
    char m_pad8[4];
    // src: GUESS (confidence: low)
    unsigned char m_flag0 : 1;
    // src: GUESS (confidence: low)
    unsigned char m_flag1 : 1;
    // src: GUESS (confidence: low)
    unsigned char m_blocking : 1;
};

int Socket_007e5630::SetBlocking(bool blocking)
{
    m_blocking = blocking;
    u_long nonBlocking = !blocking;
    return ioctlsocket(m_socket, FIONBIO, &nonBlocking) != 0 ? 7 : 0;
}
