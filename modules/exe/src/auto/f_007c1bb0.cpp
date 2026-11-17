// c5d-model: Gemini 4 Hydrogen
extern "C" char aSql_00b83e28[];
namespace Database {
    class Connection {
    public:
        __declspec(dllimport) bool __thiscall ExecuteMultiple(const char*, int) const;
    };
}
class Class_007c1bb0 {
public:
    char pad[0x3c];
    Database::Connection m_conn;
    // src: GUESS (confidence: high) [0x007c1bb0]
    bool __thiscall Exec();
};
bool Class_007c1bb0::Exec() {
    return m_conn.ExecuteMultiple(aSql_00b83e28, -1);
}
