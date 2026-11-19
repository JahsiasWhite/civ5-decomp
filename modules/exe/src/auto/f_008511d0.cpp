// Attaches the renderer: passes it the mode (virtual slot 9) and the
// 32-byte settings block (slot 10).

// src: GUESS (confidence: low)
class Renderer_008eb570
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
    virtual void SetMode(int mode);
    // src: GUESS (confidence: low)
    virtual void SetSettings(const void* settings, int size);
};

// src: GUESS (confidence: low)
class Host_008eb570
{
public:
    // src: GUESS (confidence: low) [0x008eb570]
    void Attach(Renderer_008eb570* renderer, int mode);

    char m_pad0[0x28c];
    // src: GUESS (confidence: low)
    Renderer_008eb570* m_renderer;
    // src: GUESS (confidence: low)
    char m_settings[0x20];
};

void Host_008eb570::Attach(Renderer_008eb570* renderer, int mode)
{
    m_renderer = renderer;
    if (renderer)
    {
        renderer->SetMode(mode);
        m_renderer->SetSettings(m_settings, 0x20);
    }
}
