#include "hsl.h"
#include "rgb.h"

int HSL::unused_int_a = HSL::registerQml();

//https://stackoverflow.com/a/9493060/1074799
RGB *HSL::rgb()
{
    const qreal h = m_h / 360.0, s = m_s / 100.0, l = m_l / 100.0;
    qreal r, g, b;
    if(s == 0){
        r = g = b = l; // achromatic
    }else{
        qreal q = l < 0.5 ? l * (1.0 + s) : l + s - l * s;
        qreal p = 2.0 * l - q;
        r = hueToRGB(p, q, h + 1.0/3.0);
        g = hueToRGB(p, q, h);
        b = hueToRGB(p, q, h - 1.0/3.0);
    }
    RGB *_rgb = new RGB(this);
    _rgb->setRGB(r * 255.0, g * 255.0, b * 255.0);
    return _rgb;
}

XYZ *HSL::xyz()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->xyz();
}

CMYK *HSL::cmyk()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->cmyk();
}

LAB *HSL::lab()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->lab();
}

HSV *HSL::hsv()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hsv();
}

HWB *HSL::hwb()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hwb();
}

HEX *HSL::hex()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hex();
}

qreal HSL::hueToRGB(qreal t1, qreal t2, qreal hue)
{
    if(hue < 0.0) hue += 1.0;
    if(hue > 1.0) hue -= 1.0;
    if(hue < 1.0/6.0) return t1 + (t2 - t1) * 6.0 * hue;
    if(hue < 1.0/2.0) return t2;
    if(hue < 2.0/3.0) return t1 + (t2 - t1) * (2.0/3.0 - hue) * 6.0;
    return t1;
}

void HSL::setHSL(qreal h, qreal s, qreal l)
{
    m_h = h; m_s = s; m_l = l;
    emit colorChanged();
}

