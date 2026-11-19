// Lua: passes two ints to the game owner's handler (virtual slot 81).

#include "LuaApi.h"

// src: GUESS (confidence: low)
class Handler_004d3ad0
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
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    // src: GUESS (confidence: low)
    virtual void Handle(int a, int b);
};

// src: GUESS (confidence: low)
struct GlobalOwner_0079fd50
{
    char m_pad0[0x1460];
    // src: GUESS (confidence: low)
    Handler_004d3ad0* m_handler;
};

extern GlobalOwner_0079fd50* g_pOwner_00cc8e74;

// src: GUESS (confidence: low) [0x004d3ad0]
int HandleFromLua_004d3ad0(lua_State* L)
{
    int a = lua_tointeger(L, 1);
    int b = lua_tointeger(L, 2);
    g_pOwner_00cc8e74->m_handler->Handle(a, b);
    return 0;
}
