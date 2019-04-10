#include "Plane.h"

#include <limits>
#include <iostream>

Plane::Plane(Vector3 _point, Vector3 _color, float _specular, float _lambert, float _ambiant, Vector3 _normal)
: SceneObject(_point, _color, _specular, _lambert, _ambiant), normal(_normal)
{
    //ctor
    type = "Plane";
}


Plane::Plane(const Plane& original)
: SceneObject(original), normal(original.normal)
{
    type = "Plane";
}

float Plane::intersect(const Ray& ray) const {
    float denom = normal.normalized() * ray.getDirection().normalized();
    if (denom > 1e-6) {
        Vector3 p0l0 = point - ray.getOrigin();
        return (p0l0 * normal) / denom;
    }
    return std::numeric_limits<float>::infinity();
}

const Vector3 Plane::computeNormal(const Vector3& pos) const {
    return 0.0f;
}


Plane::~Plane()
{
    //dtor
}
