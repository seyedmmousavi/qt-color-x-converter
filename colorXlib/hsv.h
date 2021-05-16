#ifndef HSV_H
#define HSV_H

#include <QObject>
#include <QDebug>
#include <QColor>
#include <QQmlApplicationEngine>

class RGB;
class LAB;
class CMYK;
class XYZ;
class HSL;
class HWB;
class HEX;

class HSV : public QObject {
    Q_OBJECT
    Q_PROPERTY(qreal h MEMBER m_h)
    Q_PROPERTY(qreal s MEMBER m_s)
    Q_PROPERTY(qreal v MEMBER m_v)
    Q_PROPERTY(HSL *hsl READ hsl NOTIFY colorChanged)
    Q_PROPERTY(XYZ *xyz READ xyz NOTIFY colorChanged)
    Q_PROPERTY(HWB *hwb READ hwb NOTIFY colorChanged)
    Q_PROPERTY(CMYK *cmyk READ cmyk NOTIFY colorChanged)
    Q_PROPERTY(RGB *rgb READ rgb NOTIFY colorChanged)
    Q_PROPERTY(LAB *lab READ lab NOTIFY colorChanged)
    Q_PROPERTY(HEX *hex READ hex NOTIFY colorChanged)

public:
    RGB *rgb();
    LAB *lab();
    CMYK *cmyk();
    HWB *hwb();
    XYZ *xyz();
    HSL *hsl();
    HEX *hex();

    qreal m_h, m_s, m_v;
    void setHSV(qreal h, qreal s, qreal v);
    Q_INVOKABLE QString string() {
        return QString("H:%1 S:%2 V:%3").arg(m_h).arg(m_s).arg(m_v);
    }
    Q_INVOKABLE QColor color();
    HSV(QObject *parent = nullptr): QObject(parent) {}

    static int registerQml()
    {
        qDebug()<< "ColorX > HSV registered";
        return qmlRegisterType<HSV>("ir.ColorXlib", 1, 0, "HSV");
    }

signals:
    void colorChanged();

private:
    static int unused_int;
};

#endif // HSV_H
