QT       += core gui sql gui multimedia multimediawidgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    crud_profiles.cpp \
    crud_utilisateurs.cpp \
    gestion_profiles.cpp \
    gestion_utilisateurs.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow2.cpp

HEADERS += \
    connexion.h \
    crud_profiles.h \
    crud_utilisateurs.h \
    gestion_profiles.h \
    gestion_utilisateurs.h \
    mainwindow.h \
    mainwindow2.h

FORMS += \
    gestion_profiles.ui \
    gestion_utilisateurs.ui \
    mainwindow.ui \
    mainwindow2.ui

TRANSLATIONS += \
    LoginAPP1_fr_FR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
