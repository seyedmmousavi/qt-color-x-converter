#include "rgb.h"
#include <QGenericMatrix>
#include <QtMath>
#include <QColor>

int RGB::unused_int = RGB::registerQml();

HSV *RGB::hsv()
{
    HSV *_hsv = new HSV(this);
    qreal rd, gd, bd, h, s;
    qreal r = m_r / 255.0;
    qreal g = m_g / 255.0;
    qreal b = m_b / 255.0;
    qreal max = qMax(r, qMax(g, b));
    qreal min = qMin(r, qMin(g, b));
    qreal delta = max - min;

    if (delta == 0) {
        h = 0;
        s = 0;
    } else {
        s = delta / max;
        rd = (max - r) / 6.0 / delta + 1.0 / 2.0;
        gd = (max - g) / 6.0 / delta + 1.0 / 2.0;
        bd = (max - b) / 6.0 / delta + 1.0 / 2.0;

        if (r == max) {
            h = bd - gd;
        } else if (g == max) {
            h = (1.0 / 3.0) + rd - bd;
        } else {
            h = (2.0 / 3.0) + gd - rd;
        }

        if (h < 0.0) {
            h++;
        } else if (h > 1.0) {
            h--;
        }

    }
    _hsv->m_h = h * 360.0;
    _hsv->m_s = s * 100.0;
    _hsv->m_v = max * 100.0;
    return _hsv;
}

HWB *RGB::hwb()
{
    HWB *_hwb = new HWB(this);

    HSL *_hsl = hsl();
    qreal h = _hsl->m_h;
    _hsl->deleteLater();

    qreal w = 1 / 255.0 * qMin(m_r, qMin(m_g, m_b));

    qreal b = 1.0 - 1.0 / 255.0 *qMax(m_r, qMax(m_g, m_b));

    _hwb->m_h = h;
    _hwb->m_w = w * 100.0;
    _hwb->m_b = b * 100.0;
    return _hwb;
}

CMYK *RGB::cmyk()
{
    CMYK *_cmyk = new CMYK(this);
    qreal r = m_r / 255.0;
    qreal g = m_g / 255.0;
    qreal b = m_b / 255.0;

    qreal c, m, y, k;
    k = 1.0 - qMax(r, qMax(g, b));

    if (k == 1.0) {
        c = m = y = 0.0;
    } else {
        c = (1.0 - r - k) / (1.0 - k);
        m = (1.0 - g - k) / (1.0 - k);
        y = (1.0 - b - k) / (1.0 - k);
    }

    _cmyk->m_c = c * 100.0;
    _cmyk->m_m = m * 100.0;
    _cmyk->m_y = y * 100.0;
    _cmyk->m_k = k * 100.0;

    return _cmyk;
}

XYZ *RGB::xyz()
{
    //Assume sRGB
    XYZ *_xyz = new XYZ(this);
    qreal r = m_r / 255.0;
    qreal g = m_g / 255.0;
    qreal b = m_b / 255.0;

    //Reference: http://www.brucelindbloom.com/index.html?Eqn_RGB_to_XYZ.html
    r = r > 0.04045 ? qPow((r + 0.055) / 1.055, 2.4) : r / 12.92;
    g = g > 0.04045 ? qPow((g + 0.055) / 1.055, 2.4) : g / 12.92;
    b = b > 0.04045 ? qPow((b + 0.055) / 1.055, 2.4) : b / 12.92;

    //Matrix: http://www.brucelindbloom.com/index.html?Eqn_RGB_XYZ_Matrix.html
    qreal rgbMatrixData[] = {r, g, b};
    qreal magicMatrixData[] = {
        0.4124564, 0.2126729, 0.0193339,
        0.3575761, 0.7151522, 0.1191920,
        0.1804375, 0.0721750, 0.9503041
    };
    QGenericMatrix<3, 3, qreal> magicMatrix(magicMatrixData);
    QGenericMatrix<3, 1, qreal> rgbMatrix(rgbMatrixData);
    QGenericMatrix<3, 1, qreal> resultMatrix = rgbMatrix * magicMatrix;
    resultMatrix *= 100.0;
    _xyz->m_x = resultMatrix.constData()[0];
    _xyz->m_y = resultMatrix.constData()[1];
    _xyz->m_z = resultMatrix.constData()[2];

    return _xyz;
}

LAB *RGB::lab()
{
    LAB *_lab = new LAB(this);
    XYZ *_xyz = xyz();
    _xyz->deleteLater();
    qreal x = _xyz->m_x / 95.047;
    qreal y = _xyz->m_y / 100.0;
    qreal z = _xyz->m_z / 108.883;
    x = x > 0.008856 ? qPow(x, 1.0 / 3.0) : (903.3 * x + 16.0) / 116.0;
    y = y > 0.008856 ? qPow(y, 1.0 / 3.0) : (903.3 * y + 16.0) / 116.0;
    z = z > 0.008856 ? qPow(z, 1.0 / 3.0) : (903.3 * z + 16.0) / 116.0;

    qreal l = 116.0 * y - 16.0;
    qreal a = 500.0 * (x - y);
    qreal b = 200.0 * (y - z);

    _lab->m_l = l;
    _lab->m_a = a;
    _lab->m_b = b;

    return _lab;
}

HEX *RGB::hex()
{
    QColor c(m_r, m_g, m_b);
    HEX *_hex = new HEX(this);
    _hex->setValue(c.name(QColor::HexRgb));
    return _hex;
}

HSL *RGB::hsl()
{
    HSL *_hsl = new HSL(this);
    qreal r = m_r / 255.0;
    qreal g = m_g / 255.0;
    qreal b = m_b / 255.0;
    qreal min = qMin(r, qMin(g, b));
    qreal max = qMax(r, qMax(g, b));
    qreal delta = max - min;
    if (max == min) {
        _hsl->m_h = 0;
    } else if (r == max) {
        _hsl->m_h = (g - b) / delta;
    } else if (g == max) {
        _hsl->m_h = (b - r) / delta + 2;
    } else if (b == max) {
        _hsl->m_h = (r - g) / delta + 4;
    }

    _hsl->m_h = qMin(_hsl->m_h * 60.0, 360.0);

    if (_hsl->m_h < 0) {
        _hsl->m_h += 360.0;
    }


    if (max == min) {
        _hsl->m_s = 0;
    } else if (_hsl->m_l <= 0.5) {
        _hsl->m_s = 100.0 * delta / (max + min);
    } else {
        _hsl->m_s = 100.0 * delta / (2 - max - min);
    }


    _hsl->m_l = 100.0 * (min + max) / 2;

    return _hsl;
}

void RGB::setRGB(qreal r, qreal g, qreal b)
{
    m_r = r; m_g = g; m_b = b;
    emit colorChanged();
}
