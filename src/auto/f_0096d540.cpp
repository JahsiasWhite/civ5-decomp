// Returns OpenSSL's built-in DSA method table.

extern int g_OpenSSLDsaMethod;

int* GetOpenSSLDsaMethod()
{
    return &g_OpenSSLDsaMethod;
}
