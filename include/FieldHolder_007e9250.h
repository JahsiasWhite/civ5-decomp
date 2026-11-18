#pragma once
// c5d-vtable: 0x00b88260

// An object whose virtuals forward to a data block returned by slot 75. The
// unnamed virtuals are placeholders in slot order.

// src: GUESS (confidence: low)
struct FieldHolderData_007e9250
{
    char m_pad0[0x1d];
    // src: GUESS (confidence: low)
    bool m_flag1d;
    // src: GUESS (confidence: low)
    bool m_flag1e;
    char m_pad1f[0x34 - 0x1f];
    // src: GUESS (confidence: low)
    bool m_flag34;
};

// src: GUESS (confidence: low) [0x00b88260]
class FieldHolder_007e9250
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    // src: GUESS (confidence: low) [0x007fe630]
    virtual void SetFlag1D(bool value);
    virtual void v04();
    // src: GUESS (confidence: low) [0x007fe680]
    virtual void SetFlag1E(bool value);
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
    // src: GUESS (confidence: low) [0x007fd680]
    virtual void SetFlag34(bool value);
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
    // src: GUESS (confidence: low) [0x007bc620]
    virtual FieldHolderData_007e9250* GetData();
};
