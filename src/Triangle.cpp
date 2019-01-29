#include "Triangle.h"

#include <math.h>
#include <limits>
#include <iostream>



Triangle::Triangle(Vector3 _point, Vector3 _color, float _specular, float _lambert, float _ambiant, Vector3 _a, Vector3 _b, Vector3 _c)
: SceneObject(_point, _color, _specular, _lambert, _ambiant), a(_a), b(_b), c(_c)
{
    //ctor
    type = "Triangle";
}


float Triangle::intersect(const Ray& ray) const {
    Vector3 bc = c - b;
    Vector3 ba = a - b;

    Vector3 normal = Vector3::crossProduct(bc, ba);
    float area2 = normal.magnitude();

    float NdotRayDirection = normal * ray.getDirection();
    // ray and plane parralel
    if(fabs(NdotRayDirection) < 1e-6) {
        return std::numeric_limits<float>::infinity();
    }

    float d = normal * b;
    float t = (normal * ray.getOrigin() + d) / NdotRayDirection;

    if(t < 0) {
        return std::numeric_limits<float>::infinity();
    }

    Vector3 rayIntersection = ray.getOrigin() + ray.getDirection() * t;

    Vector3 center = Vector3();

    //edge 0
    Vector3 edge0 = bc;
    Vector3 vp0 = rayIntersection - b;
    center = Vector3::crossProduct(edge0, vp0);
    if(normal * center < 0) {
        return std::numeric_limits<float>::infinity();
    }

    //edge 1
    Vector3 edge1 = a - c;
    Vector3 vp1 = rayIntersection - c;
    center = Vector3::crossProduct(edge1, vp1);
    if(normal * center < 0) {
        return std::numeric_limits<float>::infinity();
    }

    //edge 2
    Vector3 edge2 = b - a;
    Vector3 vp2 = rayIntersection - a;
    center = Vector3::crossProduct(edge2, vp2);
    if(normal * center < 0) {
        return std::numeric_limits<float>::infinity();
    }

    return t;
}

Vector3 Triangle::computeNormal(const Vector3& pos) const {
    return 0.0f;
}

Triangle::~Triangle()
{
    //dtor
}
