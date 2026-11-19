// src: GUESS (confidence: medium) [0x004753c0]
// c5d-cflags: +/Oy-
// src: GUESS (confidence: medium) [0x004753c0]
void __stdcall ArrayDtor_004753c0(void* pArray, unsigned int uiElemSize, int iCount, void (__thiscall* pfnDtor)(void*)) {
    pArray = (char*)pArray + uiElemSize * iCount;
    while (--iCount >= 0) {
        pArray = (char*)pArray - uiElemSize;
        (*pfnDtor)(pArray);
    }
}
