#include "Triangle.h"

#include <limits>
#include <iostream>


Triangle::Triangle(Vector3 _point, Vector3 _color, float _specular, float _lambert, float _ambiant, Vector3 _a, Vector3 _b, Vector3 _c)
: SceneObject(_point, _color, _specular, _lambert, _ambiant), a(_a), b(_b), c(_c)
{
    //ctor
    type = "Triangle";
}


float Triangle::intersect(const Ray& ray) const {
    Vector3 bc = b - c; 
    Vector3 ba = b - a;

    Vector3 normal = Vector3::crossProduct(bc, ba);
    float area2 = normal.magnitude();

    float NdotRayDirection = normal * ray.getDirection();
    if(fabs(NdotRayDirection) < 1e-6) {
        std::numeric_limits<float>::infinity();
    }

    float d = normal * b;
    float t = (normal * ray.getOrigin() + d) / NdotRayDirection;
    return 0.0f;
}

Vector3 Triangle::computeNormal(const Vector3& pos) const {
    return 0.0f;
}

Triangle::~Triangle()
{
    //dtor
}
