#include "Ray.h"

Ray::Ray(const Vector3& _origin, const Vector3& _direction)
: origin(_origin), direction(_direction)
{
    //ctor
}

Ray::Ray(const Ray& original)
: origin(original.origin), direction(original.direction)
{

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
