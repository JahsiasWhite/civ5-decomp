// src: GUESS (confidence: low)
struct UnkListNode_0078e6c0
{
    UnkListNode_0078e6c0* m_next;
    UnkListNode_0078e6c0* m_prev;
    int m_val;
};

// src: GUESS (confidence: low)
struct UnkList_0078e6c0
{
    int m_pad[2];
    UnkListNode_0078e6c0* m_head;

    int* Find_0078e6c0(int val);
};

// src: GUESS (confidence: medium) [0x0078e6c0]
int* UnkList_0078e6c0::Find_0078e6c0(int val)
{
    UnkListNode_0078e6c0* head = m_head;
    for (UnkListNode_0078e6c0* node = head->m_next; node != head; node = node->m_next)
    {
        int* p = &node->m_val;
        if (val == *p)
            return p;
    }
    return 0;
}
