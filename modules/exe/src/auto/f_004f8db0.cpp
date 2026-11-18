// Replaces the attached object, notifying the old one (virtual slot 27).

// src: GUESS (confidence: low)
class Attachment_004f8db0
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
    // src: GUESS (confidence: low)
    virtual void OnDetached();
};

// src: GUESS (confidence: low)
class Holder_004f8db0
{
public:
    // src: GUESS (confidence: low) [0x004f8db0]
    void SetAttachment(Attachment_004f8db0* attachment);

    char m_pad0[0x97b4];
    // src: GUESS (confidence: low)
    Attachment_004f8db0* m_attachment;
};

void Holder_004f8db0::SetAttachment(Attachment_004f8db0* attachment)
{
    if (m_attachment)
        m_attachment->OnDetached();
    m_attachment = attachment;
}
