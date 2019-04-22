#include "Color.h"

Color::Color(float r, float g, float b)
: Vector3(r / 255.0f, g / 255.0f, b / 255.0f)
{
    //ctor
}

Color::Color(const Vector3& vector)
: Vector3(vector.x, vector.y, vector.z)
{

}

Color::Color(const Color& copy)
: Vector3(copy.x, copy.y, copy.z)
{

}

Color Color::toRGB() const {
    return Color(red(), green(), blue());
}

Color::~Color()
{
    //dtor
}
