#ifndef COLOR_H
#define COLOR_H

#include "Vector3.h"

class Color : public Vector3
{
    public:
        Color(float x = 0, float y = 0, float z = 0);
        Color(const Vector3& color);
        Color(const Color& copy);
        float red() const { return x * 255.0f; };
        float green() const { return y * 255.0f; };
        float blue() const { return z * 255.0f; };
        Color toRGB() const;
        virtual ~Color();

    protected:

    private:
};

#endif // COLOR_H
