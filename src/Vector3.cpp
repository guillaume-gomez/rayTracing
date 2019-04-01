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

Vector3 Vector3::operator+(const Vector3& source) const {
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

Vector3 Vector3::operator-(const Vector3& source) const {
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

Vector3 Vector3::operator*(const float coeff) const {
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

float Vector3::operator*(const Vector3 source) const {
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

bool operator==(const Vector3& lhs, const Vector3& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

bool operator!=(const Vector3& lhs, const Vector3& rhs) {
    return !(lhs == rhs);
}

Vector3 Vector3::crossProduct(const Vector3 a, const Vector3 b) {
    return Vector3(
        (a.y * b.z) - (a.z * b.y),
        (a.z * b.x) - (a.x * b.z),
        (a.x * b.y) - (a.y * b.x)
    );
}

Vector3 Vector3::crossProduct(const Vector3 b) {
    return Vector3(
        (y * b.z) - (z * b.y),
        (z * b.x) - (x * b.z),
        (x * b.y) - (y * b.x)
    );
}


float Vector3::magnitude() {
    return sqrt(magnitude_sqr());
}

float Vector3::magnitude() const {
    return sqrt(magnitude_sqr());
}

float Vector3::magnitude_sqr() {
    return (x * x) + (y * y) + (z * z);
}

float Vector3::magnitude_sqr() const {
    return (x * x) + (y * y) + (z * z);
}

Vector3 Vector3::normalized() {
    return Vector3(*this) / magnitude();
}

Vector3 Vector3::normalized() const {
    return Vector3(*this) / magnitude();
}

Vector3& Vector3::normalize() {
    (*this) /= magnitude();
    return *this;
}

Vector3 Vector3::unitVector() {
    float scale = 1.0f / magnitude();
    return (*this) * scale;
}

std::ostream& operator<< (std::ostream& stream, const Vector3& vector) {
    stream << "{ x: " << vector.x << ", y: " << vector.y << ", z: " << vector.z << " }";
    return stream;
}

Vector3 operator/ (const float r, const Vector3 &v) {
    return Vector3(r / v.x, r / v.y, r / v.z);
}


Vector3 Vector3::inverse() const {
    return Vector3(1.0f / x, 1.0f / y, 1.0f / z);
}

Vector3::~Vector3()
{
    //dtor
}

