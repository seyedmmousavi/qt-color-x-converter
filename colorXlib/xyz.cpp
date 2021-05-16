#include "xyz.h"
#include <QGenericMatrix>
#include <QtMath>
#include "rgb.h"

int XYZ::unused_int = XYZ::registerQml();

void XYZ::setXYZ(qreal x, qreal y, qreal z)
{
    m_x = x; m_y = y; m_z = z;
    emit colorChanged();
}

RGB *XYZ::rgb()
{
    //http://www.brucelindbloom.com/index.html?Equations.html
    RGB *_rgb = new RGB(this);
    qreal x, y, z;
    x = m_x / 100.0;
    y = m_y / 100.0;
    z = m_z / 100.0;

    qreal r, g, b;
    qreal xyzMatrixData[] = {x, y, z};
    qreal magicMatrixData[] = {
        3.2404542, -0.9692660, 0.0556434,
        -1.5371385, 1.8760108, -0.2040259,
        -0.4985314, 0.0415560, 1.0572252
    };
    QGenericMatrix<3, 3, qreal> magicMatrix(magicMatrixData);
    QGenericMatrix<3, 1, qreal> xyzMatrix(xyzMatrixData);
    QGenericMatrix<3, 1, qreal> resultMatrix = xyzMatrix * magicMatrix;
    r = resultMatrix.data()[0];
    g = resultMatrix.data()[1];
    b = resultMatrix.data()[2];

    //Assume sRGB
    r = r > 0.0031308 ? (1.055 * qPow(r, 1.0 / 2.4) - 0.055) : r * 12.92;
    g = g > 0.0031308 ? (1.055 * qPow(g, 1.0 / 2.4) - 0.055) : g * 12.92;
    b = b > 0.0031308 ? (1.055 * qPow(b, 1.0 / 2.4) - 0.055) : b * 12.92;
    r = 255.0 * qMin(qMax(0.0, r), 1.0);
    g = 255.0 * qMin(qMax(0.0, g), 1.0);
    b = 255.0 * qMin(qMax(0.0, b), 1.0);

    _rgb->setRGB(r, g, b);
    return _rgb;
}

LAB *XYZ::lab()
{
    qreal x, y, z;
    x = m_x / 95.047;
    y = m_y / 100.0;
    z = m_z / 108.883;

    x = x > 0.008856 ? qPow(x, 1.0 / 3.0) : (903.3 * x + 16.0) / 116.0;
    y = y > 0.008856 ? qPow(y, 1.0 / 3.0) : (903.3 * y + 16.0) / 116.0;
    z = z > 0.008856 ? qPow(z, 1.0 / 3.0) : (903.3 * z + 16.0) / 116.0;

    qreal l = 116.0 * y - 16.0;
    qreal a = 500.0 * (x - y);
    qreal b = 200.0 * (y - z);

    LAB *_lab = new LAB(this);
    _lab->setLAB(l, a, b);
    return _lab;
}

CMYK *XYZ::cmyk()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->cmyk();
}

HWB *XYZ::hwb()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hwb();
}

HSV *XYZ::hsv()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hsv();
}

HSL *XYZ::hsl()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hsl();
}

HEX *XYZ::hex()
{
    RGB *_rgb = rgb();
    _rgb->deleteLater();
    return _rgb->hex();
}
