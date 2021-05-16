#include "cmyk.h"
#include "rgb.h"

int CMYK::unused_int_a = CMYK::registerQml();

//https://github.com/Qix-/color-convert/blob/master/conversions.js
RGB *CMYK::rgb()
{
    const qreal c = m_c / 100.0;
    const qreal m = m_m / 100.0;
    const qreal y = m_y / 100.0;
    const qreal k = m_k / 100.0;

    const qreal r = 1.0 - qMin(1.0, c * (1.0 - k) + k);
    const qreal g = 1.0 - qMin(1.0, m * (1.0 - k) + k);
    const qreal b = 1.0 - qMin(1.0, y * (1.0 - k) + k);

    RGB *_rgb = new RGB(this);
    _rgb->setRGB(r * 255.0, g * 255.0, b * 255.0);
    return _rgb;
}

LAB *CMYK::lab()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->lab();
}

HSV *CMYK::hsv()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hsv();
}

HWB *CMYK::hwb()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hwb();
}

XYZ *CMYK::xyz()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->xyz();
}

HSL *CMYK::hsl()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hsl();
}

HEX *CMYK::hex()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hex();
}

void CMYK::setCMYK(qreal c, qreal m, qreal y, qreal k)
{
    m_c = c; m_m = m; m_y = y; m_k = k;
    emit colorChanged();
}
