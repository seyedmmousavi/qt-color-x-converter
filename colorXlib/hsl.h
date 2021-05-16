#ifndef HSL_H
#define HSL_H

#include <QObject>
#include <QDebug>
#include <QQmlApplicationEngine>

class RGB;
class XYZ;
class CMYK;
class HSV;
class HWB;
class LAB;
class HEX;

class HSL : public QObject {
    Q_OBJECT
    Q_PROPERTY(qreal h MEMBER m_h)
    Q_PROPERTY(qreal s MEMBER m_s)
    Q_PROPERTY(qreal l MEMBER m_l)
    Q_PROPERTY(HWB *hwb READ hwb NOTIFY colorChanged)
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
    HWB *hwb();
    HEX *hex();

    qreal m_h, m_s, m_l;
    void setHSL(qreal h, qreal s, qreal l);
    Q_INVOKABLE QString string() {
        return QString("H:%1 S:%2 L:%3").arg(m_h).arg(m_s).arg(m_l);
    }
    HSL(QObject *parent = nullptr): QObject(parent) {}

    static int registerQml()
    {
        qDebug()<< "ColorX > HSL registered";
        return qmlRegisterType<HSL>("ir.ColorXlib", 1, 0, "HSL");
    }

signals:
    void colorChanged();

private:
    static int unused_int_a;
    qreal hueToRGB(qreal t1, qreal t2, qreal hue);
};

#endif // HSL_H
