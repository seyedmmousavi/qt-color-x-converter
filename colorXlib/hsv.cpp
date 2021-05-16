#include "hsv.h"
#include <QtMath>
#include "rgb.h"

int HSV::unused_int = HSV::registerQml();

//https://github.com/Qix-/color-convert/blob/master/conversions.js
RGB *HSV::rgb()
{
    const qreal h = m_h / 60.0;
    const qreal s = m_s / 100.0;
    qreal v = m_v / 100.0;

    const int hi = qFloor(h) % 6;
    const double f = h - qFloor(h);
    const double p = 255.0 * v * (1.0 - s);
    const double q = 255.0 * v * (1.0 - (s * f));
    const double t = 255.0 * v * (1.0 - (s * (1.0 - f)));
    v *= 255.0;

    RGB *_rgb = new RGB(this);
    switch (hi) {
    case 0: _rgb->setRGB(v, t, p); break;
    case 1: _rgb->setRGB(q, v, p); break;
    case 2: _rgb->setRGB(p, v, t); break;
    case 3: _rgb->setRGB(p, q, v); break;
    case 4: _rgb->setRGB(t, p, v); break;
    case 5: _rgb->setRGB(v, p, q); break;
    }
    return _rgb;
}

LAB *HSV::lab()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->lab();
}

CMYK *HSV::cmyk()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->cmyk();
}

HWB *HSV::hwb()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hwb();
}

XYZ *HSV::xyz()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->xyz();
}

HSL *HSV::hsl()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hsl();
}

HEX *HSV::hex()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hex();
}

void HSV::setHSV(qreal h, qreal s, qreal v)
{
    m_h = h; m_s = s; m_v = v;
    emit colorChanged();
}
