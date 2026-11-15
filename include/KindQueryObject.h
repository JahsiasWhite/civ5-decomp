// Minimal layout of an object queried through vtable slot 24 (byte offset 0x60).
// c5d-vtable: 0x00a462e8
// GetKindFlags (0x005faa60) is virtual slot 23 and GetConstant_005acb70 is slot 18
// (see `c5d classes 0x00a462e8`); they are declared non-virtual here because
// nothing calls them through the vtable yet.
#pragma once

class KindQueryObject
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
    virtual int GetKind();

    int GetKindFlags();

    char pad04[0xA8];
    int m_ac;
};
