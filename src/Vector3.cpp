#include "Vector3.h"

Vector3::Vector3(float _x, float _y, float _z)
: x(_x), y(_y), z(_z)
{

}

Vector3::Vector3(const Vector3& original)
: x(original.x), y(original.y), z(original.z)
{

}

Vector3 Vector3::operator+(const Vector3& source) {
    Vector3(x + source.x, y + source.y, z + source.z);
}

Vector3& Vector3::operator+=(const Vector3& source) {
    x = x + source.x;
    y = y + source.y;
    z = z + source.z;
}

Vector3::~Vector3()
{
    //dtor
}

