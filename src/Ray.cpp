#include "Ray.h"

Ray::Ray(const Vector3& _origin, const Vector3& _direction)
: origin(_origin), direction(_direction)
{
    computeInverseDirection();
}

Ray::Ray(const Ray& original)
: origin(original.origin), direction(original.direction), inverseDirection(original.inverseDirection)
{
    computeInverseDirection();
}

Ray& Ray::operator=(const Ray& source) {
    origin = source.origin;
    direction = source.direction;
    return *this;
}

void Ray::setDirection(Vector3 _direction) { 
    direction = _direction;
    computeInverseDirection();
};

void Ray::computeInverseDirection() {
    inverseDirection = 1 / direction;
    sign[0] = (inverseDirection.x < 0);
    sign[1] = (inverseDirection.y < 0);
    sign[2] = (inverseDirection.z < 0);
}

Ray::~Ray()
{
    //dtor
}
