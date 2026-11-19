// c5d-cflags: -/EHsc +/GS-
#include <cstring>
#include <string>
namespace Database {
class Connection;
// src: GUESS (confidence: low) [0x10073c30]
struct ListNode_10073c30 {
    ListNode_10073c30* next;
    ListNode_10073c30* prev;
    char pad[0x24 - 8];
};
// src: GUESS (confidence: low) [0x10073c30]
struct List_10073c30 {
    int pad0;
    ListNode_10073c30* head;
    size_t size;
    List_10073c30() {
        ListNode_10073c30* n = (ListNode_10073c30*)operator new(0x24);
        if (n) n->next = n;
        ListNode_10073c30** pprev = &n->prev;
        if (pprev) *pprev = n;
        head = n;
        size = 0;
    }
};
// src: EXE [0x10073c30]
class XMLSerializer {
public:
    XMLSerializer(Connection& conn);
private:
    char m_buf1[0x100];
    char m_buf2[0x200];
    Connection* m_conn;
    int m_f304;
    int m_f308;
    bool m_f30c;
    List_10073c30 m_list;
    std::string m_str;
};
XMLSerializer::XMLSerializer(Connection& conn)
    : m_conn(&conn), m_f304(0), m_f308(0), m_f30c(true)
{
    memset(m_buf1, 0, sizeof(m_buf1));
    memset(m_buf2, 0, sizeof(m_buf2));
}
}
