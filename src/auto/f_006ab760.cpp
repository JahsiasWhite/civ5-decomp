// Walks a singly linked chain of nodes and returns the last node before the
// sentinel (the node with its end flag set). The link field is the first
// member, so the head slot itself can serve as the starting "node".

struct ChainNode
{
    ChainNode* next;
    char pad[0x111];
    bool isEnd;
};

ChainNode* FindLastBeforeChainEnd(ChainNode* node)
{
    while (!node->next->isEnd)
        node = node->next;
    return node;
}
