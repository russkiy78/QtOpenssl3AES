#include "qtopenssl3aes.h"

QtOpenssl3AES::QtOpenssl3AES()
{
}

bool QtOpenssl3AES::decrypt(QByteArray &plainText, QByteArray keyAES, QByteArray ivAES, QByteArray cipherText)
{

    if (keyAES.size() < MIN_KEY_LENGTH)
        return false;

    unsigned char* plaintext;
    plaintext = (unsigned char *) OPENSSL_malloc(cipherText.size());

    unsigned char* ciphertext = reinterpret_cast<unsigned char*>(cipherText.data());
    int ciphertext_len = cipherText.size();

    unsigned char* iv = reinterpret_cast<unsigned char*>(ivAES.data());

    unsigned char* key = reinterpret_cast<unsigned char*>(keyAES.data());

    EVP_CIPHER_CTX *ctx;
    int plaintext_len;
    int len;

    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);


    EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len);
    plaintext_len = len;


    EVP_DecryptFinal_ex(ctx, plaintext + len, &len);
    plaintext_len += len;

     plainText = QByteArray(reinterpret_cast<char*>(plaintext),plaintext_len);

    OPENSSL_free(plaintext);
    EVP_CIPHER_CTX_free(ctx);
}


bool QtOpenssl3AES::encrypt (QByteArray plainText, QByteArray keyAES, QByteArray ivAES, QByteArray &cipherText) {

    if (keyAES.size() < MIN_KEY_LENGTH)
        return false;

    unsigned char* ciphertext;
    ciphertext = (unsigned char *) OPENSSL_malloc(plainText.size()*2);

    unsigned char* plaintext = reinterpret_cast<unsigned char*>(plainText.data());
    int plaintext_len = plainText.size();

    unsigned char* iv = reinterpret_cast<unsigned char*>(ivAES.data());

    unsigned char* key = reinterpret_cast<unsigned char*>(keyAES.data());

    EVP_CIPHER_CTX *ctx;
    int ciphertext_len;
    int len;

    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len);
    ciphertext_len = len;

    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);
    ciphertext_len += len;

    cipherText = QByteArray(reinterpret_cast<char*>(ciphertext),ciphertext_len);

    EVP_CIPHER_CTX_free(ctx);

    return true;

}

