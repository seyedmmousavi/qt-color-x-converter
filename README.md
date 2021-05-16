# qt-color-x-converter
A Qt library for converting color systems

Currently fully supports RGB, XYZ, HSL, HSV, CMYK, HEX, LAB, HWB.

## How to use
1- Import library:
  - include `colorxlib.h` in your `main.cpp` file
  - register QML library by calling `ColorXlib::registerQml()` in `main.cpp` (uses old way to register types)

2- Use library in QML like this:
  ```qml
  Text {
      text: ColorX.rgb(0, 191, 253).xyz.string()    //use string() method to get string presentation
  }
  Text {
      text: ColorX.rgb(0, 191, 253).xyz.x   //each parameter is accessible by its name
  }
  Text {
      text: ColorX.xyz(36.353, 44.3485, 99.5535).lab.hwb.rgb.string()    //un-necessary complex but is possible
  }
  Rectangle {
      width: 20; height: 20
      color: ColorX.xyz(36.353, 44.3485, 99.5535).color()   //you can use other systems colors as this
  }
  Rectangle {
      width: 20; height: 20
      color: ColorX.xyz(36.353, 44.3485, 99.5535).rgb.color()   //every system objects can return color (note: returned color object is base on rgb)
  }
  ```
  
