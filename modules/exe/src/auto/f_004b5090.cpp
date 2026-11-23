// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low) [0x004b5090]
struct GUID4b5090 {
    unsigned int Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

extern GUID4b5090 g_guid_4b5090;

struct I4b5090 {
    virtual int __stdcall Query(GUID4b5090 guid) = 0;
};

int __stdcall fn_004b5090(I4b5090* p) {
    return p->Query(g_guid_4b5090);
}
