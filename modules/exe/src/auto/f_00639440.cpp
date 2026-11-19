// Finds the layer whose key matches; -1 when none of the 68 layers does.

// src: GUESS (confidence: low)
struct Key_0057e720
{
    int m_a;
    int m_b;
};

// src: GUESS (confidence: low)
struct Layer_0057e720
{
    // src: GUESS (confidence: low)
    Key_0057e720 m_key;
    char m_pad8[0x2d60 - 8];
};

// src: GUESS (confidence: low)
class Layers_0057e720
{
public:
    // src: GUESS (confidence: low) [0x0057e720]
    int Find(const Key_0057e720* key) const;

    char m_pad0[0x278];
    // src: GUESS (confidence: low)
    Layer_0057e720 m_layers[0x44];
};

int Layers_0057e720::Find(const Key_0057e720* key) const
{
    for (int i = 0; i < 0x44; ++i)
    {
        if (key->m_b == m_layers[i].m_key.m_b && key->m_a == m_layers[i].m_key.m_a)
            return i;
    }
    return -1;
}
