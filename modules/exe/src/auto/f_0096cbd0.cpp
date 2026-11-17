// Returns OpenSSL's built-in ECDSA method table.

extern int g_OpenSSLEcdsaMethod;

int* GetOpenSSLEcdsaMethod()
{
    return &g_OpenSSLEcdsaMethod;
}
