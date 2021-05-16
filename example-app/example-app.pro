QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../colorXlib/release/ -lcolorXlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../colorXlib/debug/ -lcolorXlib
else:unix: LIBS += -L$$OUT_PWD/../colorXlib/ -lcolorXlib

INCLUDEPATH += $$PWD/../colorXlib
DEPENDPATH += $$PWD/../colorXlib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../colorXlib/release/libcolorXlib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../colorXlib/debug/libcolorXlib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../colorXlib/release/colorXlib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../colorXlib/debug/colorXlib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../colorXlib/libcolorXlib.a
