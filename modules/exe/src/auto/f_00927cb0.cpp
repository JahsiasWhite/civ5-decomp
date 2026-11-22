// c5d-cflags: +/GS-
// src: GUESS (confidence: high) [0x00927cb0]
#include <winsock2.h>
#include <stdlib.h>

extern void __cdecl f_009363f0();

void __cdecl f_00927cb0() {
    __declspec(align(8)) WSADATA wsaData;
    if (WSAStartup(0x202, &wsaData) != 0) {
        abort();
    }
    atexit(f_009363f0);
}
