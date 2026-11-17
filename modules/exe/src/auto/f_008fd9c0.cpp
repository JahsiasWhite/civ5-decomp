// Returns the 32-bit field at offset 0x220.

class Field220Holder_008fd9c0
{
public:
    int GetField220() const;

    char pad0[0x220];
    int m_field220;
};

int Field220Holder_008fd9c0::GetField220() const
{
    return m_field220;
}
