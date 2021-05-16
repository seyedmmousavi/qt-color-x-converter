#ifndef COLORXLIB_H
#define COLORXLIB_H
#include <QObject>
#include <QColor>
#include <QQmlEngine>
#include "rgb.h"

class ColorXlib : public QObject
{
    Q_OBJECT

public:
    ColorXlib(QObject *parent = nullptr);
    Q_INVOKABLE RGB *rgb(qreal r, qreal g, qreal b);
    Q_INVOKABLE XYZ *xyz(qreal x, qreal y, qreal z);
    Q_INVOKABLE HWB *hwb(qreal h, qreal w, qreal b);
    Q_INVOKABLE HSL *hsl(qreal h, qreal s, qreal l);
    static int registerQml();

private:
    enum class ColorType {
        RGB, HSL, CMYK, HEX, HSV, HWB, LAB, XYZ
    };

    QColor m_color;
    ColorType m_colorType;
    static int ununsed_val;
    static QObject *colorXSingletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine);
};

#endif // COLORXLIB_H
