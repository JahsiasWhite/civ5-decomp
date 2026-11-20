// c5d-cflags: +/GS-
#include <winsock2.h>

// src: GUESS (confidence: high) [0x00432b20]
bool InitWinsock_00432b20()
{
    __declspec(align(8)) WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) == 0)
        return true;
    return false;
}
