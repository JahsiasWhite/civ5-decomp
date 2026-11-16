// c5d-model: Gemini 4 Hydrogen
// c5d-cflags: -/EHsc -/arch:SSE2
struct lua_State;

extern "C" {
    void __cdecl _lua_pushstring(lua_State*, const char*);
    int  __cdecl lua_gettop(lua_State*);
    void __cdecl _lua_createtable(lua_State*, int, int);
    void __cdecl _lua_rawset(lua_State*, int);
    void __cdecl _lua_pushvalue(lua_State*, int);
    void __cdecl lua_rawseti(lua_State*, int, int);

    extern const char aDisplayName[];
    extern const char aType[];
    extern const char aPath[];
    extern const char aSelectTypeDisplayNamePathFromLocalizationSpokenLanguages[];
}

namespace Database {
    class Results {
    public:
        int data[15];
        __declspec(dllimport) Results(const char*);
        __declspec(dllimport) virtual ~Results();
        __declspec(dllimport) bool __thiscall Step();
        __declspec(dllimport) const char* __thiscall GetText(int);
    };
    class Connection {
    public:
        __declspec(dllimport) bool __thiscall Execute(Results&, const char*, int) const;
    };
}

struct GlobalOwner_0079fd50 {
    char pad[0x944];
    Database::Connection m_db;
};
extern GlobalOwner_0079fd50* g_pOwner_00cc8e74;

// src: GUESS (confidence: high) [0x0074b3b0]
int __cdecl Lua_GetSpokenLanguages_0074b3b0(lua_State* L) {
    _lua_pushstring(L, aDisplayName);
    int idxDisplayName = lua_gettop(L);
    _lua_pushstring(L, aType);
    int idxType = lua_gettop(L);
    _lua_pushstring(L, aPath);
    int idxPath = lua_gettop(L);
    _lua_createtable(L, 0, 0);
    int idxResult = lua_gettop(L);

    int row = 1;
    Database::Results results(0);
    Database::Connection* pDb = &g_pOwner_00cc8e74->m_db;
    if (pDb->Execute(results, aSelectTypeDisplayNamePathFromLocalizationSpokenLanguages, -1) && results.Step()) {
        do {
            _lua_createtable(L, 0, 2);
            _lua_pushvalue(L, idxType);
            _lua_pushstring(L, results.GetText(0));
            _lua_rawset(L, -3);
            _lua_pushvalue(L, idxDisplayName);
            _lua_pushstring(L, results.GetText(1));
            _lua_rawset(L, -3);
            _lua_pushvalue(L, idxPath);
            _lua_pushstring(L, results.GetText(2));
            _lua_rawset(L, -3);
            lua_rawseti(L, idxResult, row++);
        } while (results.Step());
    }
    return 1;
}
