#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>

class Vector3
{
    public:
     union {
        float data[3];
        struct {
            float x;
            float y;
            float z;
        };
    };

        Vector3(float x = 0, float y = 0, float z = 0);
        Vector3(const Vector3& copy);
        Vector3& operator=(const Vector3& source);
        Vector3 operator+(const Vector3& source);
        Vector3 operator+(const Vector3& source) const;
        Vector3& operator+=(const Vector3& source);
        Vector3 operator-(const Vector3& source);
        Vector3 operator-(const Vector3& source) const;
        Vector3& operator-=(const Vector3& source);
        Vector3 operator*(const float coeff);
        Vector3 operator*(const float coeff) const;
        Vector3& operator*=(const float coeff);
        Vector3 operator/(const float coeff);
        Vector3& operator/=(const float coeff);
        float operator*(const Vector3 source);
        float operator*(const Vector3 source) const;
        Vector3 operator^(const Vector3 source);
        Vector3& operator^=(const Vector3 source);
        float magnitude();
        float magnitude() const;
        float magnitude_sqr();
        float magnitude_sqr() const;
        Vector3 normalized();
        Vector3 normalized() const;
        Vector3& normalize();
        Vector3 unitVector();
        Vector3 inverse() const;
        static Vector3 crossProduct(const Vector3 a, const Vector3 b);
        Vector3 crossProduct(const Vector3 b);
        virtual ~Vector3();
        friend Vector3 operator/(const float r, const Vector3 &v);
        friend std::ostream& operator<<(std::ostream& stream, const Vector3& vector);
        friend bool operator==(const Vector3& lhs, const Vector3& rhs);
        friend bool operator!=(const Vector3& lhs, const Vector3& rhs);
    protected:
    private:
};

#endif // VECTOR3_H
