#pragma once
// c5d-vtable: 0x00b88260

// An object whose virtuals forward to a data block returned by slot 75 (and a
// second block from slot 73, and a linked object from slot 106). The unnamed
// virtuals are placeholders in slot order.

// src: GUESS (confidence: low)
struct FieldHolderData_007e9250
{
    char m_pad0[0x1d];
    // src: GUESS (confidence: low)
    bool m_flag1d;
    // src: GUESS (confidence: low)
    bool m_flag1e;
    char m_pad1f[0x28 - 0x1f];
    // src: GUESS (confidence: low)
    int m_value28;
    char m_pad2c[0x34 - 0x2c];
    // src: GUESS (confidence: low)
    bool m_flag34;
};

// src: GUESS (confidence: low)
struct FieldHolderInfo_007e9250
{
    int m_00;
    // src: GUESS (confidence: low)
    int m_value04;
    // src: GUESS (confidence: low)
    int m_value08;
    char m_padc[0x24 - 0xc];
    // src: GUESS (confidence: low)
    int m_value24;
};

// src: GUESS (confidence: low)
class FieldHolderLinked_007e9250
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
    // src: GUESS (confidence: low)
    virtual void Apply9(int value);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    // src: GUESS (confidence: low)
    virtual bool Query13();
    // src: GUESS (confidence: low)
    virtual bool Query14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    // src: GUESS (confidence: low)
    virtual void Apply20(int value);
    // src: GUESS (confidence: low)
    virtual int Query21();
    // src: GUESS (confidence: low)
    virtual bool Query22();
    // src: GUESS (confidence: low)
    virtual int Query23();
    // src: GUESS (confidence: low)
    virtual int Query24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    // src: GUESS (confidence: low)
    virtual int Query28();
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
    // src: GUESS (confidence: low) [0x007fe6b0]
    virtual bool GetFlag1E();
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
    // src: GUESS (confidence: low) [0x007fd6f0]
    virtual int GetData28();
    virtual void v33();
    // src: GUESS (confidence: low) [0x007fd770]
    virtual int GetInfo24();
    // src: GUESS (confidence: low) [0x007fd7a0]
    virtual int GetInfo08();
    // src: GUESS (confidence: low) [0x007fd7d0]
    virtual int GetInfo04();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    // src: GUESS (confidence: low) [0x007f3660]
    virtual bool QueryLinked22();
    // src: GUESS (confidence: low) [0x007f3690]
    virtual bool QueryLinked13();
    // src: GUESS (confidence: low) [0x007f36c0]
    virtual bool QueryLinked14();
    // src: GUESS (confidence: low) [0x007f36f0]
    virtual int QueryLinked28();
    // src: GUESS (confidence: low) [0x007fd860]
    virtual bool IsEither();
    // src: GUESS (confidence: low)
    virtual bool Check48();
    // src: GUESS (confidence: low)
    virtual bool Check49();
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
    // src: GUESS (confidence: low) [0x007fb210]
    virtual FieldHolderInfo_007e9250* GetInfo();
    virtual void v74();
    // src: GUESS (confidence: low) [0x007bc620]
    virtual FieldHolderData_007e9250* GetData();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    // src: GUESS (confidence: low) [0x007fed30]
    virtual void ApplyLinked9(int value);
    virtual void v86();
    // src: GUESS (confidence: low) [0x007fedf0]
    virtual void ApplyLinked20(int value);
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    // src: GUESS (confidence: low) [0x007feea0]
    virtual int QueryLinked23();
    // src: GUESS (confidence: low) [0x007feed0]
    virtual int QueryLinked24();
    // src: GUESS (confidence: low) [0x007fef00]
    virtual int QueryLinked21();
    // src: GUESS (confidence: low) [0x007fef90]
    virtual void SetFlag84(bool value);
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    // src: GUESS (confidence: low) [0x007fb290]
    virtual FieldHolderLinked_007e9250* GetLinked();

    char m_pad04[0x84 - 4];
    // src: GUESS (confidence: low)
    bool m_flag84;
};
