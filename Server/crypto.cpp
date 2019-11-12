#include "crypto.h"



crypto::crypto()
{
}


crypto::~crypto()
{
}

QByteArray crypto::encrypt(QByteArray message)
{
    QByteArray arr;
    TinyAES aes;
    arr = aes.Encrypt(message, password);

    return arr;
}

QByteArray crypto::decrypt(QByteArray message)
{
    QByteArray arr;
    TinyAES aes;
    arr = aes.Decrypt(message, password);

    return arr;
}
