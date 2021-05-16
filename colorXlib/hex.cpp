#include "hex.h"
#include <QColor>
#include "rgb.h"

RGB *HEX::rgb()
{
    QColor c(m_value);
    RGB *_rgb = new RGB(this);
    _rgb->setRGB(c.redF() * 255, c.greenF() * 255, c.blueF() * 255);
    return _rgb;
}

XYZ *HEX::xyz()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->xyz();
}

CMYK *HEX::cmyk()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->cmyk();
}

LAB *HEX::lab()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->lab();
}

HSV *HEX::hsv()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hsv();
}

HWB *HEX::hwb()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hwb();
}

HSL *HEX::hsl()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hsl();
}

void HEX::setValue(QString hex)
{
    m_value = hex;
    emit colorChanged();
}
