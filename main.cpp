#include <QDebug>
#include <QString>
#include "qtopenssl3aes.h"


int main() {

    QByteArray keyAES = QString("rt1231sdf111111110").toUtf8();
    QByteArray ivAES = QString("rtytd324234234234234234234234ds fds sd ryrt").toUtf8();
    QByteArray plainText = QString("123ewqrkjhdaes oaeswhdfoewhfdaslfkh daslfkhdsfldshfldshf dlsf dsf ds fds fdsf dsf dsfdsf;sdmlf;ldsmmd;s f;dsl mfd;sfl mds;fl dmsk;fldsmf ;dslf md;sfl ,mds;flds;flds ;fldskf;dsl fkd;slf kds;lfkds;fldks;f lsdhklkh321").toUtf8();
    QByteArray cipherText;
    QByteArray input2;


    QtOpenssl3AES::encrypt (plainText, keyAES, ivAES, cipherText);

    qDebug()<< "cipherText"<< cipherText;

    plainText.clear();

    QtOpenssl3AES::decrypt(plainText, keyAES, ivAES, cipherText);

    qDebug()<< "plainText"<< plainText;

}
