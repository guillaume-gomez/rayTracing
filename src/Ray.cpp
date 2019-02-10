#include "Ray.h"

Ray::Ray(const Vector3& _origin, const Vector3& _direction)
: origin(_origin), direction(_direction)
{
    inverseDirection = direction.inverse();
    sign[0] = (inverseDirection.x < 0);
    sign[1] = (inverseDirection.y < 0);
    sign[2] = (inverseDirection.z < 0);
}

Ray::Ray(const Ray& original)
: origin(original.origin), direction(original.direction), inverseDirection(original.inverseDirection)
{
    sign[0] = (inverseDirection.x < 0);
    sign[1] = (inverseDirection.y < 0);
    sign[2] = (inverseDirection.z < 0);
}

Ray& Ray::operator=(const Ray& source) {
    origin = source.origin;
    direction = source.direction;
    return *this;
}

Ray::~Ray()
{
    //dtor
}
