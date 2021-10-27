QT -= gui

TEMPLATE = lib
DEFINES += QTOPENSSL3AES_LIBRARY

CONFIG += c++11
# CONFIG += c++11 console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    qtopenssl3aes.cpp

HEADERS += \
    QtOpenssl3AES_global.h \
    qtopenssl3aes.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/libs/openssl/include
DEPENDPATH += $$PWD/libs/openssl/include

unix|win32: LIBS += -L$$OUT_PWD/  -lcrypto
