#include "colorxlib.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QDebug>
#include "rgb.h"

ColorXlib::ColorXlib(QObject *parent) : QObject(parent)
{

}

RGB *ColorXlib::rgb(qreal r, qreal g, qreal b)
{
    m_colorType = ColorXlib::ColorType::RGB;
    RGB *rgb = new RGB(this);
    rgb->setRGB(r, g, b);
    return rgb;
}

XYZ *ColorXlib::xyz(qreal x, qreal y, qreal z)
{
    m_colorType = ColorXlib::ColorType::XYZ;
    XYZ *xyz = new XYZ(this);
    xyz->setXYZ(x, y, z);
    return xyz;
}

HWB *ColorXlib::hwb(qreal h, qreal w, qreal b)
{
    m_colorType = ColorXlib::ColorType::HWB;
    HWB *hwb = new HWB(this);
    hwb->setHWB(h, w, b);
    return hwb;
}

HSL *ColorXlib::hsl(qreal h, qreal s, qreal l)
{
    m_colorType = ColorXlib::ColorType::HSL;
    HSL *hsl= new HSL(this);
    hsl->setHSL(h, s, l);
    return hsl;
}

QObject *ColorXlib::colorXSingletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    //QJSValue value = scriptEngine->newObject();
    return new ColorXlib();
}

int ColorXlib::registerQml()
{
    qDebug() << "ColorX > ColorX registered";
    return qmlRegisterSingletonType<ColorXlib>("ir.ColorXlib", 1, 0, "ColorX", &ColorXlib::colorXSingletonProvider);
}

