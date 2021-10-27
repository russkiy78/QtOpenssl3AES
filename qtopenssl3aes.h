#ifndef QTOPENSSL3AES_H
#define QTOPENSSL3AES_H

#include "QtOpenssl3AES_global.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QDebug>
#include <QRandomGenerator>
#include <QFile>
#include <QString>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/encoder.h>

#define MIN_KEY_LENGTH 18

class QTOPENSSL3AES_EXPORT QtOpenssl3AES
{
public:
    QtOpenssl3AES();
    static bool encrypt (QByteArray plainText, QByteArray keyAES, QByteArray ivAES, QByteArray &cipherText);
    static bool decrypt (QByteArray &plainText, QByteArray keyAES, QByteArray ivAES, QByteArray cipherText);
};

#endif // QTOPENSSL3AES_H
