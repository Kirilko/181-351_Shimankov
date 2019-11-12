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

QByteArray crypto::randomBytes(int size){
    unsigned char arr[size];
    RAND_bytes(arr,size);

    QByteArray buffer = QByteArray(reinterpret_cast<char*>(arr),size);
    return buffer;
}
QByteArray crypto::encryptAES(QByteArray passphrase, QByteArray &data){
    QByteArray msalt = randomBytes(SALTSIZE);
    int round = 1;
    unsigned char key[KEYSIZE];
    unsigned char iv[IVSIZE];

    const unsigned char *salt = (const unsigned char*)msalt.constData();
    const unsigned char *pass = (const unsigned char*)passphrase.constData();

    int i = EVP_BytesToKey(EVP_aes_256_cbc(),EVP_sha1(),salt,pass,passphrase.length(),round,key,iv);
    if(i!=KEYSIZE){
        qCritical() << "EVP_BytesToKey() error " << ERR_error_string(ERR_get_error(),NULL);
        return QByteArray();
    }
    EVP_CIPHER_CTX *en;
    en = EVP_CIPHER_CTX_new();
   // EVP_CIPHER_CTX_init(&en);
    if(!EVP_EncryptInit_ex(en,EVP_aes_256_cbc(),NULL,key,iv)){
        qCritical() << "EVP_EncryptInit_ex() failed" << ERR_error_string(ERR_get_error(),NULL);
        return QByteArray();
    }
    char *input = data.data();
    char *out;
    int len = data.size();

    int c_len = len + AES_BLOCK_SIZE, f_len = 0;
    unsigned char *ciphertext = (unsigned char*)malloc(c_len);

    /*if(!EVP_EncryptInit_ex(en,NULL,NULL,NULL,NULL)){
        qCritical() << "EVP_EncryptInit_ex() failed" << ERR_error_string(ERR_get_error(),NULL);
        return QByteArray();
    }*/
    if(!EVP_EncryptUpdate(en, ciphertext,&c_len,(unsigned char*)input,len)){
        qCritical() << "EVP_EncryptUpdate() failed" << ERR_error_string(ERR_get_error(),NULL);
        return QByteArray();
    }
    if(!EVP_EncryptFinal(en,ciphertext+c_len,&f_len)){
        qCritical() << "EVP_EncodeFina() failed" << ERR_error_string(ERR_get_error(),NULL);
        return QByteArray();
    }
    len = c_len + f_len;
    out = (char*)ciphertext;
    //EVP_CIPHER_CTX_cipher(en);

    QByteArray encrypted = QByteArray(reinterpret_cast<char*>(ciphertext), len);
    QByteArray finished;
    finished.append("Crypted:");
    finished.append(msalt);
    //finished.append(out,len);
    finished.append(encrypted);
    EVP_CIPHER_CTX_cleanup(en);
    free(ciphertext);
    return finished;
}
QByteArray crypto::decryptAES(QByteArray passphrase, QByteArray &data){
    QByteArray msalt;
    if(QString(data.mid(0,8)) == "Crypted:"){
        msalt = data.mid(8,8);
        data = data.mid(16);
    }
    else{
        qWarning() << "Couldn't load salt from data";
        msalt = randomBytes(SALTSIZE);
    }

    int round = 1;
    unsigned char key[KEYSIZE];
    unsigned char iv[IVSIZE];

    const unsigned char *salt = (const unsigned char*)msalt.constData();
    const unsigned char *pass = (const unsigned char*)passphrase.constData();

    int i = EVP_BytesToKey(EVP_aes_256_cbc(),EVP_sha1(),salt,pass,passphrase.length(),round,key,iv);
    if(i!=KEYSIZE){
        qCritical() << "EVP_BytesToKey() error " << ERR_error_string(ERR_get_error(),NULL);
        return QByteArray();
    }
    EVP_CIPHER_CTX *de;
    de = EVP_CIPHER_CTX_new();

    if(!EVP_DecryptInit_ex(de,EVP_aes_256_cbc(),NULL,key,iv)){
            qCritical() << "EVP_EncryptInit_ex() failed" << ERR_error_string(ERR_get_error(),NULL);
            return QByteArray();
    }
    char *input = data.data();
    char *out;
    int len = data.size();

    int p_len = len, f_len = 0;
    unsigned char *plaintext = (unsigned char*)malloc(p_len + AES_BLOCK_SIZE);
    if(!EVP_DecryptUpdate(de,plaintext,&p_len,(unsigned char*)input, len)){
        qCritical() << "EVP_DecryptUpdate() error " << ERR_error_string(ERR_get_error(),NULL);
        return QByteArray();
    }
    if(!EVP_DecryptFinal(de,plaintext+p_len,&f_len)){
        qCritical() << "EVP_DecryptFinal() failed" << ERR_error_string(ERR_get_error(),NULL);
        return QByteArray();
    }
    len = p_len + f_len;
    out = (char*)plaintext;
    EVP_CIPHER_CTX_cleanup(de);
    QByteArray decrypted = QByteArray(reinterpret_cast<char*>(plaintext), len);
    free(plaintext);
    return decrypted;
    //return QByteArray(out, len);
}
