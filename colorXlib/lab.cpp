#include "lab.h"
#include "xyz.h"
#include <QtMath>

int LAB::unused_int_a = LAB::registerQml();

RGB *LAB::rgb()
{
    XYZ* _xyz = xyz();
    _xyz->deleteLater();
    return _xyz->rgb();
}

XYZ *LAB::xyz()
{
    const qreal l = m_l;
    const qreal a = m_a;
    const qreal b = m_b;
    qreal y = (l + 16.0) / 116.0;
    qreal x = a / 500.0 + y;
    qreal z = y - b / 200.0;
    const qreal x2 = qPow(x, 3.0);
    const qreal y2 = qPow(y, 3.0);
    const qreal z2 = qPow(z, 3.0);
    y = y2 > 0.008856 ? y2 : (y - 16.0 / 116.0) / (903.3 / 116.0);
    x = x2 > 0.008856 ? x2 : (x - 16.0 / 116.0) / (903.3 / 116.0);
    z = z2 > 0.008856 ? z2 : (z - 16.0 / 116.0) / (903.3 / 116.0);

    x *= 95.047;
    y *= 100;
    z *= 108.883;

    XYZ *_xyz = new XYZ(this);
    _xyz->setXYZ(x, y, z);
    return _xyz;
}

CMYK *LAB::cmyk()
{
    XYZ* _xyz = xyz();
    _xyz->deleteLater();
    return _xyz->cmyk();
}

HWB *LAB::hwb()
{
    XYZ* _xyz = xyz();
    _xyz->deleteLater();
    return _xyz->hwb();
}

HSV *LAB::hsv()
{
    XYZ* _xyz = xyz();
    _xyz->deleteLater();
    return _xyz->hsv();
}

HSL *LAB::hsl()
{
    XYZ* _xyz = xyz();
    _xyz->deleteLater();
    return _xyz->hsl();
}

HEX *LAB::hex()
{
    XYZ *_xyz = xyz();
    _xyz->deleteLater();
    return _xyz->hex();
}

void LAB::setLAB(qreal l, qreal a, qreal b)
{
    m_l = l; m_a = a; m_b = b;
    emit colorChanged();
}
