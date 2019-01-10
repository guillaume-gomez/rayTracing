#ifndef RAY_H
#define RAY_H

#include "Vector3.h"

class Ray
{
    public:
        Ray(const Vector3& origin = Vector3(0.0f, 0.0f, 0.0f), const Vector3& direction = Vector3(0.0f, 0.0f, 0.0f));
        Ray(const Ray& original);
        Ray& operator=(const Ray& source);
        virtual ~Ray();
        const Vector3& getOrigin() const { return origin; };
        const Vector3& getDirection() const { return direction; };
        void setOrigin(Vector3 _origin ) { origin = _origin; };
        void setDirection(Vector3 _direction) { direction = _direction; };
    protected:
        Vector3 origin;
        Vector3 direction;
};

#endif // RAY_H
