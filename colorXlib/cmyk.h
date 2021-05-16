#ifndef CMYK_H
#define CMYK_H

#include <QObject>
#include <QDebug>
#include <QQmlApplicationEngine>

class RGB;
class LAB;
class HSV;
class XYZ;
class HSL;
class HWB;
class HEX;

class CMYK : public QObject {
    Q_OBJECT
    Q_PROPERTY(qreal c MEMBER m_c)
    Q_PROPERTY(qreal m MEMBER m_m)
    Q_PROPERTY(qreal y MEMBER m_y)
    Q_PROPERTY(qreal k MEMBER m_k)
    Q_PROPERTY(HSL *hsl READ hsl NOTIFY colorChanged)
    Q_PROPERTY(XYZ *xyz READ xyz NOTIFY colorChanged)
    Q_PROPERTY(HWB *hwb READ hwb NOTIFY colorChanged)
    Q_PROPERTY(HSV *hsv READ hsv NOTIFY colorChanged)
    Q_PROPERTY(RGB *rgb READ rgb NOTIFY colorChanged)
    Q_PROPERTY(LAB *lab READ lab NOTIFY colorChanged)
    Q_PROPERTY(HEX *hex READ hex NOTIFY colorChanged)

public:
    RGB *rgb();
    LAB *lab();
    HSV *hsv();
    HWB *hwb();
    XYZ *xyz();
    HSL *hsl();
    HEX *hex();

    qreal m_c, m_m, m_y, m_k;
    void setCMYK(qreal c, qreal m, qreal y, qreal k);
    Q_INVOKABLE QString string() {
        return QString("C:%1 M:%2 Y:%3 K:%4").arg(m_c).arg(m_m).arg(m_y).arg(m_k);
    }
    CMYK(QObject *parent = nullptr): QObject(parent) {}

    static int registerQml()
    {
        qDebug()<< "ColorX > CMYK registered";
        return qmlRegisterType<CMYK>("ir.ColorXlib", 1, 0, "CMYK");
    }

signals:
    void colorChanged();

private:
    static int unused_int_a;
};

#endif // CMYK_H
