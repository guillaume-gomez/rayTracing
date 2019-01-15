#include "Plane.h"

#include <limits>

Plane::Plane(Vector3 _point, Vector3 _color, float _specular, float _lambert, float _ambiant, Vector3 _normal)
: SceneObject(_point, _color, _specular, _lambert, _ambiant), normal(_normal)
{
    //ctor
    type = "Plane";
}

float Plane::intersect(const Ray& ray) const {
    float denom = normal.normalized() * ray.getDirection().normalized();
    if (denom > 1e-6) {
        Vector3 p0l0 = point - ray.getDirection();
        return (p0l0 * normal) / denom;
    }
    return std::numeric_limits<float>::infinity();
}

Vector3 Plane::computeNormal(const Vector3& pos) const {
    return 0.0f;
}


Plane::~Plane()
{
    //dtor
}
