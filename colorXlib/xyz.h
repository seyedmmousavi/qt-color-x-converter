#ifndef XYZ_H
#define XYZ_H
#include <QObject>
#include <QDebug>
#include <QColor>
#include <QQmlApplicationEngine>

class RGB;
class LAB;
class CMYK;
class HSV;
class HSL;
class HWB;
class HEX;

class XYZ : public QObject {
    Q_OBJECT
    Q_PROPERTY(qreal x MEMBER m_x)
    Q_PROPERTY(qreal y MEMBER m_y)
    Q_PROPERTY(qreal z MEMBER m_z)
    Q_PROPERTY(HSL *hsl READ hsl NOTIFY colorChanged)
    Q_PROPERTY(HSV *hsv READ hsv NOTIFY colorChanged)
    Q_PROPERTY(HWB *hwb READ hwb NOTIFY colorChanged)
    Q_PROPERTY(CMYK *cmyk READ cmyk NOTIFY colorChanged)
    Q_PROPERTY(RGB *rgb READ rgb NOTIFY colorChanged)
    Q_PROPERTY(LAB *lab READ lab NOTIFY colorChanged)
    Q_PROPERTY(HEX *hex READ hex NOTIFY colorChanged)

public:
    void setXYZ(qreal x, qreal y, qreal z);

    RGB *rgb();
    LAB *lab();
    CMYK *cmyk();
    HWB *hwb();
    HSV *hsv();
    HSL *hsl();
    HEX *hex();

    qreal m_x, m_y, m_z;
    Q_INVOKABLE QString string() {
        return QString("X:%1 Y:%2 Z:%3").arg(m_x).arg(m_y).arg(m_z);
    }
    Q_INVOKABLE QColor color();
    XYZ(QObject *parent = nullptr): QObject(parent) {}

    static int registerQml()
    {
        qDebug()<< "ColorX > XYZ registered";
        return qmlRegisterType<XYZ>("ir.ColorXlib", 1, 0, "XYZ");
    }
signals:
    void colorChanged();
private:
    static int unused_int;
};

#endif // XYZ_H
