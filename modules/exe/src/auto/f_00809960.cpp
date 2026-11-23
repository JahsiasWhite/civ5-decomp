// c5d-cflags: -/O2 -/Ob1 +/Od
// src: GUESS (confidence: low)
extern int* g_2c72cbc;

void f_00809960() {
    int* a1 = 0;
    int* a3 = g_2c72cbc;
    int a2 = *a3 & 0x7fffffff;
    while ((((*a3 & 0x7fffffff) >> 30) == 1) == 0) {
        if (((*a3 >> 31) == 0) != 0) {
            if (a1 != 0) {
                *a1 = (*a1 & 0x7fffffff) + a2 + 4;
                *a1 = *a1 & 0x7fffffff;
                a2 = *a1 & 0x7fffffff;
                a3 = a1;
            } else {
                a1 = a3;
            }
        } else {
            a1 = 0;
        }
        a3 = (int*)((char*)a3 + a2 + 4);
        a2 = *a3 & 0x7fffffff;
    }
}
