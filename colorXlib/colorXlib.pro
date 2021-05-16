QT = gui qml

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cmyk.cpp \
    colorxlib.cpp \
    hex.cpp \
    hsl.cpp \
    hsv.cpp \
    hwb.cpp \
    lab.cpp \
    rgb.cpp \
    xyz.cpp

HEADERS += \
    cmyk.h \
    colorxlib.h \
    hex.h \
    hsl.h \
    hsv.h \
    hwb.h \
    lab.h \
    rgb.h \
    xyz.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.md
