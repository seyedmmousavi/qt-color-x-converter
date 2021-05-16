#ifndef HWB_H
#define HWB_H

#include <QObject>
#include <QDebug>
#include <QQmlApplicationEngine>

class RGB;
class XYZ;
class CMYK;
class HSV;
class HSL;
class LAB;
class HEX;

class HWB :public QObject {
    Q_OBJECT
    Q_PROPERTY(qreal h MEMBER m_h)
    Q_PROPERTY(qreal w MEMBER m_w)
    Q_PROPERTY(qreal b MEMBER m_b)
    Q_PROPERTY(HSL *hsl READ hsl NOTIFY colorChanged)
    Q_PROPERTY(HSV *hsv READ hsv NOTIFY colorChanged)
    Q_PROPERTY(LAB *lab READ lab NOTIFY colorChanged)
    Q_PROPERTY(CMYK *cmyk READ cmyk NOTIFY colorChanged)
    Q_PROPERTY(RGB *rgb READ rgb NOTIFY colorChanged)
    Q_PROPERTY(XYZ *xyz READ xyz NOTIFY colorChanged)
    Q_PROPERTY(HEX *hex READ hex NOTIFY colorChanged)

public:
    RGB *rgb();
    XYZ *xyz();
    CMYK *cmyk();
    LAB *lab();
    HSV *hsv();
    HSL *hsl();
    HEX *hex();

    qreal m_h, m_w, m_b;
    void setHWB(qreal h, qreal w, qreal b);
    Q_INVOKABLE QString string() {
        return QString("H:%1 W:%2 B:%3").arg(m_h).arg(m_w).arg(m_b);
    }
    HWB(QObject *parent = nullptr): QObject(parent) {}

    static int registerQml()
    {
        qDebug()<< "ColorX > HWB registered";
        return qmlRegisterType<HWB>("ir.ColorXlib", 1, 0, "HWB");
    }

signals:
    void colorChanged();

private:
    static int unused_int_a;
};


#endif // HWB_H
