#include "Vector3.h"
#include <math.h>

Vector3::Vector3(float _x, float _y, float _z)
: x(_x), y(_y), z(_z)
{

}

Vector3::Vector3(const Vector3& original)
: x(original.x), y(original.y), z(original.z)
{

}

Vector3& Vector3::operator=(const Vector3& source) {
    x = source.x;
    y = source.y;
    z = source.z;
    return *this;
}

Vector3 Vector3::operator+(const Vector3& source) {
    return Vector3(x + source.x, y + source.y, z + source.z);
}

Vector3& Vector3::operator+=(const Vector3& source) {
    x = x + source.x;
    y = y + source.y;
    z = z + source.z;
    return *this;
}

Vector3 Vector3::operator-(const Vector3& source) {
    return Vector3(x - source.x, y - source.y, z - source.z);
}

Vector3& Vector3::operator-=(const Vector3& source) {
    x = x - source.x;
    y = y - source.y;
    z = z - source.z;
    return *this;
}

Vector3 Vector3::operator*(const float coeff) {
    return Vector3(x * coeff, y * coeff, z * coeff);
}

Vector3& Vector3::operator*=(const float coeff) {
    x = x * coeff;
    y = y * coeff;
    z = z * coeff;
    return *this;
}

Vector3 Vector3::operator/(const float coeff) {
    return Vector3(x / coeff, y / coeff, z / coeff);
}

Vector3& Vector3::operator/=(const float coeff) {
    x = x / coeff;
    y = y / coeff;
    z = z / coeff;
    return *this;
}

float Vector3::operator*(const Vector3 source) {
    return (x * source.x) + (y * source.y) + (z * source.z);
}

Vector3 Vector3::operator^(const Vector3 source) {
    float nx = y * source.z - source.y * z;
    float ny = z * source.x - source.z * x;
    float nz = x * source.y - source.x * y;
    return Vector3(nx, ny, nz);
}

Vector3& Vector3::operator^=(const Vector3 source) {
    float nx = y * source.z - source.y * z;
    float ny = z * source.x - source.z * x;
    float nz = x * source.y - source.x * y;
    x = nx;
    y = ny;
    z = nz;
    return *this;
}

float Vector3::magnitude() {
    return sqrt(magnitude_sqr());
}

float Vector3::magnitude_sqr() {
    return (x * x) + (y * y) + (z * z);
}

Vector3 Vector3::normalised() {
    return Vector3(*this) / magnitude();
}

Vector3& Vector3::normalise() {
    (*this) /= magnitude();
    return *this;
}

Vector3 Vector3::unitVector() {
    float scale = 1.0f / magnitude();
    return (*this) * scale;
}


Vector3::~Vector3()
{
    //dtor
}

