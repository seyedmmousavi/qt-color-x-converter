How to expose c++ struct to qml:
    struct HSV {
        Q_GADGET
        Q_PROPERTY(qreal h MEMBER m_h)
        Q_PROPERTY(qreal s MEMBER m_s)
        Q_PROPERTY(qreal v MEMBER m_v)
        public:
        qreal m_h, m_s, m_v;
    };
    Q_DECLARE_METATYPE(HSV)

Most important reference:
    https://github.com/Qix-/color-convert/blob/master/conversions.js

Other references:
    https://www.w3schools.com/lib/w3color.js
