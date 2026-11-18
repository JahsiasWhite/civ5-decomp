// Returns the lazily built registration entry for this handler.

// src: GUESS (confidence: low) [0x0088ebe0]
void Handler_0088ebe0();

// src: GUESS (confidence: low)
struct Registration_00469be0
{
    Registration_00469be0(int id, void (*handler)())
        : m_id(id)
        , m_handler(handler)
    {
    }

    // src: GUESS (confidence: low)
    int m_id;
    // src: GUESS (confidence: low)
    void (*m_handler)();
};

// src: GUESS (confidence: low) [0x00469be0]
Registration_00469be0* GetRegistration_00469be0()
{
    static Registration_00469be0 s_registration(0, Handler_0088ebe0);
    return &s_registration;
}
