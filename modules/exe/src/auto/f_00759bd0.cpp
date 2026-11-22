// src: GUESS (confidence: high) [0x00759bd0]
const wchar_t* __stdcall getHttpMethod_00759bd0(int method) {
    switch (method) {
        case 1: return L"POST";
        case 2: return L"HEAD";
        case 3: return L"PUT";
        case 4: return L"DELETE";
        case 5: return L"TRACE";
        case 6: return L"OPTIONS";
        case 7: return L"CONNECT";
        default: return L"GET";
    }
}
