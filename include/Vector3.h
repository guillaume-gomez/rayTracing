#ifndef VECTOR3_H
#define VECTOR3_H


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
        Vector3& operator+=(const Vector3& source);
        Vector3 operator-(const Vector3& source);
        Vector3& operator-=(const Vector3& source);
        Vector3 operator*(const float coeff);
        Vector3& operator*=(const float coeff);
        Vector3 operator/(const float coeff);
        Vector3& operator/=(const float coeff);
        float operator*(const Vector3 source);
        Vector3 operator^(const Vector3 source);
        Vector3& operator^=(const Vector3 source);
        float magnitude();
        float magnitude_sqr();
        Vector3 normalised();
        Vector3& normalise();
        Vector3 unitVector();
        static  Vector3 crossProduct(const Vector3 a, const Vector3 b);
        Vector3 crossProduct(const Vector3 b);
        virtual ~Vector3();
    protected:
    private:
};

#endif // VECTOR3_H
