// src: LIB (sqlite3)
extern "C" int sqlite3_config(int op, ...);
// src: GUESS (confidence: low)
extern "C" int g_memMethods_1007849c;
// src: GUESS (confidence: low)
extern "C" int g_pcacheBuf_10089a40;
// src: GUESS (confidence: low)
extern "C" int g_heapBuf_10087ee0;

// src: GUESS 0x100013d0 (confidence: high)
void ConfigureSqlite_100013d0() {
    sqlite3_config(4, &g_memMethods_1007849c);
    sqlite3_config(7, &g_pcacheBuf_10089a40, 0x490, 5000);
    sqlite3_config(6, &g_heapBuf_10087ee0, 0x1b60, 1);
    sqlite3_config(13, 0, 0);
}
