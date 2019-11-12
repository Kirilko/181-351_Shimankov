#pragma once

#include <QString>
#include <qbytearray.h>
#include <string>
#include <TinyAES.h>


#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")

class crypto
{
public:
    crypto();
    ~crypto();

    QByteArray encrypt(QByteArray message);
    QByteArray decrypt(QByteArray message);
    QByteArray password = "d4af1bc61f60a73064e4f599da1fb378";

    //unsigned char *key = (unsigned char *)"0123456789"; // ïàðîëü (êëþ÷)
    //unsigned char *iv = (unsigned char *)"0123456789012345"; // èíèöèàëèçèðóþùèé âåêòîð, ðàíäîìàéçåð


};
