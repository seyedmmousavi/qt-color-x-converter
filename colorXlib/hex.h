#ifndef HEX_H
#define HEX_H

#include <QObject>
#include <QDebug>
#include <QQmlApplicationEngine>

class RGB;
class XYZ;
class CMYK;
class HSV;
class HWB;
class LAB;
class HSL;

class HEX : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString value MEMBER m_value)
    Q_PROPERTY(HWB *hwb READ hwb NOTIFY colorChanged)
    Q_PROPERTY(HSV *hsv READ hsv NOTIFY colorChanged)
    Q_PROPERTY(LAB *lab READ lab NOTIFY colorChanged)
    Q_PROPERTY(CMYK *cmyk READ cmyk NOTIFY colorChanged)
    Q_PROPERTY(RGB *rgb READ rgb NOTIFY colorChanged)
    Q_PROPERTY(XYZ *xyz READ xyz NOTIFY colorChanged)
    Q_PROPERTY(HSL *hsl READ hsl NOTIFY colorChanged)
public:
    RGB *rgb();
    XYZ *xyz();
    CMYK *cmyk();
    LAB *lab();
    HSV *hsv();
    HWB *hwb();
    HSL *hsl();

    void setValue(QString hex);

    Q_INVOKABLE QString string() {
        return QString("%1").arg(m_value);
    }
    HEX(QObject *parent = nullptr): QObject(parent) {}

    static int registerQml()
    {
        qDebug()<< "ColorX > HEX registered";
        return qmlRegisterType<HEX>("ir.ColorXlib", 1, 0, "HEX");
    }

signals:
    void colorChanged();

private:
    QString m_value;
};

#endif // HEX_H
