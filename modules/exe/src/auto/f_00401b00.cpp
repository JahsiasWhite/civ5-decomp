// src: GUESS (confidence: low) [0x00401b00]
struct Class_00401b00 {
    void* vptr;
    const char* m_what;
    const char* what() const;
};
const char* Class_00401b00::what() const {
    return m_what ? m_what : "unknown exception";
}
