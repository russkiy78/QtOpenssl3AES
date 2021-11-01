# QtOpenssl3AES
Qt C++ wrapper for OpenSSL# AES implementation

#  Installation

## Linux

copy all files from directory /libs/openssl/lib/linux/ to your run dir.


## WIN64

copy all files from directory /libs/openssl/lib/win/ to your run dir.


# API

```
    static bool encrypt (QByteArray plainText, QByteArray keyAES, QByteArray ivAES, QByteArray &cipherText, const EVP_CIPHER* algo = EVP_aes_256_cbc());
``` 
    Encrypt plainText to cipherText with using "algo" algorithm.
    Full list of algorithms you can find here https://www.openssl.org/docs/man1.0.2/man3/EVP_EncryptInit.html
    
```    
    static bool decrypt (QByteArray &plainText, QByteArray keyAES, QByteArray ivAES, QByteArray cipherText, const EVP_CIPHER* algo = EVP_aes_256_cbc());
``` 
    Decrypt cipherText to plainText with using  "algo" 
    Full list of algorithms you can find here https://www.openssl.org/docs/man1.0.2/man3/EVP_EncryptInit.html

