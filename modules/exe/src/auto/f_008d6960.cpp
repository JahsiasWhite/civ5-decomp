// Returns OpenSSL's built-in ECDH method table.

extern int g_OpenSSLEcdhMethod;

int* GetOpenSSLEcdhMethod()
{
    return &g_OpenSSLEcdhMethod;
}
