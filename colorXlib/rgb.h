//#ifndef RGB_H
//#define RGB_H
#pragma once
#include <QObject>
#include <QDebug>
#include <QQmlApplicationEngine>
#include "hsl.h"
#include "hsv.h"
#include "hwb.h"
#include "cmyk.h"
#include "xyz.h"
#include "lab.h"
#include "hex.h"

class RGB : public QObject {
    Q_OBJECT
    Q_PROPERTY(qreal r MEMBER m_r)
    Q_PROPERTY(qreal g MEMBER m_g)
    Q_PROPERTY(qreal b MEMBER m_b)
    Q_PROPERTY(HSL *hsl READ hsl NOTIFY colorChanged)
    Q_PROPERTY(HSV *hsv READ hsv NOTIFY colorChanged)
    Q_PROPERTY(HWB *hwb READ hwb NOTIFY colorChanged)
    Q_PROPERTY(CMYK *cmyk READ cmyk NOTIFY colorChanged)
    Q_PROPERTY(XYZ *xyz READ xyz NOTIFY colorChanged)
    Q_PROPERTY(LAB *lab READ lab NOTIFY colorChanged)
    Q_PROPERTY(HEX *hex READ hex NOTIFY colorChanged)

public:
    void setRGB(qreal r, qreal g, qreal b);

    HSL *hsl();

    HSV *hsv();

    HWB *hwb();

    CMYK *cmyk();

    XYZ *xyz();

    LAB *lab();

    HEX *hex();

    qreal m_r, m_g, m_b;
    Q_INVOKABLE QString string() {
        return QString("R:%1 G:%2 B:%3").arg(m_r).arg(m_g).arg(m_b);
    }
    RGB(QObject *parent = nullptr): QObject(parent) {}
    static int registerQml()
    {
        qDebug()<< "ColorX > RGB registered";
        return qmlRegisterType<RGB>("ir.ColorXlib", 1, 0, "RGB");
    }

signals:
    void colorChanged();

private:
    static int unused_int;
};

//#endif // RGB_H
