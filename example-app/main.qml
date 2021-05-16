import QtQuick 2.12
import QtQuick.Window 2.12
import ir.ColorXlib 1.0

Window {
    width: 440
    height: 680
    visible: true
    title: qsTr("Hello World")


    Column {
        spacing: 10
        Row {
            spacing: 10
            Text {
                text: "Base RGB is R:%1 G:%2 B:%3".arg(0).arg(191).arg(253);
            }
            Rectangle {
                width: 20; height: 20
                color: ColorX.rgb(0, 191, 253).xyz.color()
            }
        }
        Rectangle {
            width: parent.width; height: 1; color: "#eee"
        }
        Text {
            text: "XYZ> %1".arg(ColorX.rgb(0, 191, 253).xyz.string())
        }
        Text {
            text: "XYZ>RGB> %1".arg(ColorX.rgb(0, 191, 253).xyz.rgb.string())
        }
        Rectangle {
            width: parent.width; height: 1; color: "#eee"
        }
        Text {
            text: "LAB> %1".arg(ColorX.rgb(0, 191, 253).lab.string())
        }
        Text {
            text: "LAB>RGB> %1".arg(ColorX.rgb(0, 191, 253).lab.rgb.string())
        }
        Rectangle {
            width: parent.width; height: 1; color: "#eee"
        }
        Text {
            text: "HSL> %1".arg(ColorX.rgb(0, 191, 253).hsl.string())
        }
        Text {
            text: "HSL>RGB> %1".arg(ColorX.rgb(0, 191, 253).hsl.rgb.string())
        }
        Rectangle {
            width: parent.width; height: 1; color: "#eee"
        }
        Text {
            text: "HWB> %1".arg(ColorX.rgb(0, 191, 253).hwb.string())
        }
        Text {
            text: "HWB>RGB> %1".arg(ColorX.rgb(0, 191, 253).hwb.rgb.string())
        }
        Rectangle {
            width: parent.width; height: 1; color: "#eee"
        }
        Text {
            text: "HSV> %1".arg(ColorX.rgb(0, 191, 253).hsv.string())
        }
        Text {
            text: "HSV>RGB> %1".arg(ColorX.rgb(0, 191, 253).hsv.rgb.string())
        }
        Rectangle {
            width: parent.width; height: 1; color: "#eee"
        }
        Text {
            text: "CMYK> %1".arg(ColorX.rgb(0, 191, 253).cmyk.string())
        }
        Text {
            text: "CMYK>RGB> %1".arg(ColorX.rgb(0, 191, 253).cmyk.rgb.string())
        }
        Rectangle {
            width: parent.width; height: 1; color: "#eee"
        }
        Text {
            text: "HEX> %1".arg(ColorX.rgb(0, 191, 253).hex.string())
        }
        Text {
            text: "HEX>RGB> %1".arg(ColorX.rgb(0, 191, 253).hex.rgb.string())
        }
        Rectangle {
            width: parent.width; height: 1; color: "#eee"
        }
        Text {
            text: "XYZ to LAB > " + ColorX.xyz(36.353, 44.3485, 99.5535).lab.string();
        }
        Text {
            text: "HSL to RGB > " + ColorX.hsl(194.704, 100, 49.6078).rgb.string();
        }
        Text {
            text: "HWB to RGB > " + ColorX.hwb(194.704, 0.0, 0.784314).rgb.string();
        }
    }
}
