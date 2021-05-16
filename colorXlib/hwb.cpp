#include "hwb.h"
#include "rgb.h"
#include "hsl.h"
#include <QtMath>

int HWB::unused_int_a = HWB::registerQml();

//https://github.com/Qix-/color-convert/blob/master/conversions.js
RGB *HWB::rgb()
{

    const qreal h = m_h / 360.0;
    qreal wh = m_w / 100.0;
    qreal bl = m_b / 100.0;

    const qreal ratio = wh + bl;

    if (ratio > 1.0) {
        wh /= ratio;
        bl /= ratio;
    }

    const int i = qFloor(6 * h);
    const qreal v = 1.0 - bl;
    qreal f = 6.0 * h - i;

    if ((i & 1) != 0) {    //if i is odd
        f = 1.0 - f;
    }

    const qreal n = wh + f * (v - wh);
    qreal r, g, b;

    switch (i) {
    default:
    case 6:
    case 0: r = v; g = n; b = wh; break;
    case 1: r = n; g = v; b = wh; break;
    case 2: r = wh; g = v; b = n; break;
    case 3: r = wh; g = n; b = v; break;
    case 4: r = n; g = wh; b = v; break;
    case 5: r = v; g = wh; b = n; break;
    }

    RGB *_rgb = new RGB(this);
    _rgb->setRGB(r * 255.0, g * 255.0, b * 255.0);
    return _rgb;
}

XYZ *HWB::xyz()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->xyz();
}

CMYK *HWB::cmyk()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->cmyk();
}

LAB *HWB::lab()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->lab();
}

HSV *HWB::hsv()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hsv();
}

HSL *HWB::hsl()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hsl();
}

HEX *HWB::hex()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hex();
}

void HWB::setHWB(qreal h, qreal w, qreal b)
{
    m_h = h; m_w = w; m_b = b;
    emit colorChanged();
}

QColor HWB::color()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->color();
}
