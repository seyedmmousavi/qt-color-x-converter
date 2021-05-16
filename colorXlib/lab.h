#ifndef LAB_H
#define LAB_H

#include <QObject>
#include <QDebug>
#include <QQmlApplicationEngine>

class RGB;
class XYZ;
class CMYK;
class HSV;
class HSL;
class HWB;
class HEX;

class LAB : public QObject {
    Q_OBJECT
    Q_PROPERTY(qreal l MEMBER m_l)
    Q_PROPERTY(qreal a MEMBER m_a)
    Q_PROPERTY(qreal b MEMBER m_b)
    Q_PROPERTY(HSL *hsl READ hsl NOTIFY colorChanged)
    Q_PROPERTY(HSV *hsv READ hsv NOTIFY colorChanged)
    Q_PROPERTY(HWB *hwb READ hwb NOTIFY colorChanged)
    Q_PROPERTY(CMYK *cmyk READ cmyk NOTIFY colorChanged)
    Q_PROPERTY(RGB *rgb READ rgb NOTIFY colorChanged)
    Q_PROPERTY(XYZ *xyz READ xyz NOTIFY colorChanged)
    Q_PROPERTY(HEX *hex READ hex NOTIFY colorChanged)

public:
    RGB *rgb();
    XYZ *xyz();
    CMYK *cmyk();
    HWB *hwb();
    HSV *hsv();
    HSL *hsl();
    HEX *hex();

    qreal m_l, m_a, m_b;
    void setLAB(qreal l, qreal a, qreal b);
    Q_INVOKABLE QString string() {
        return QString("L:%1 A:%2 B:%3").arg(m_l).arg(m_a).arg(m_b);
    }
    LAB(QObject *parent = nullptr): QObject(parent) {}

    static int registerQml()
    {
        qDebug()<< "ColorX > LAB registered";
        return qmlRegisterType<LAB>("ir.ColorXlib", 1, 0, "LAB");
    }

signals:
    void colorChanged();

private:
    static int unused_int_a;
};

#endif // LAB_H
