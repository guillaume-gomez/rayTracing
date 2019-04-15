#include "Disk.h"

#include <limits>

Disk::Disk(Vector3 _point, Vector3 _color, float _specular, float _lambert, float _ambiant, Vector3 _normal, float _radius)
: Plane(_point, _color, _specular, _lambert, _ambiant, _normal), radius(_radius)
{
    //ctor
    type = "Disk";
}

Disk::Disk(const Disk& original)
: Plane(original), radius(original.radius)
{
    type = "Disk";
}

float Disk::intersect(const Ray& ray) const {

    float t = Plane::intersect(ray);
    float radius2 = radius * radius;

    if(t < std::numeric_limits<float>::infinity() ) {
        //check if intersection is in circle
        Vector3 IntersectionPlane = ray.getOrigin() + ray.getDirection() * t;
        Vector3 distance = IntersectionPlane - point;
        float d2 = distance * distance;
        if(d2 <= radius2) {
            return t;
        } else {
            return std::numeric_limits<float>::infinity();
        }
    }
    return t;
}

const Vector3 Disk::computeNormal(const Vector3& pos) const {
    return normal;
}


Disk::~Disk()
{
    //dtor
}
