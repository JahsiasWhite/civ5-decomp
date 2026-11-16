// Clears a one-byte flag stored after the object's first field.

class FlagAt4Holder
{
public:
    void ClearFlag();

private:
    int m_field0;
    bool m_flag;
};

void FlagAt4Holder::ClearFlag()
{
    m_flag = false;
}
