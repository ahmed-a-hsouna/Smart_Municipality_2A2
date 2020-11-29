QT       += core gui sql network printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    citoyent.cpp \
    commerciale.cpp \
    connexion.cpp \
    fenetre.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    citoyent.h \
    commerciale.h \
    connexion.h \
    fenetre.h \
    mainwindow.h

FORMS += \
    fenetre.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc

DISTFILES +=
