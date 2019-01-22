#include "Sphere.h"
#include <math.h>

#include <limits>
#include <iostream>

Sphere::Sphere(Vector3 _point, Vector3 _color, float _specular, float _lambert, float _ambiant, float _radius)
: SceneObject(_point, _color, _specular, _lambert, _ambiant), radius(_radius)
{
    // Point attribute means center here
    type = "Sphere";
}

float Sphere::intersect(const Ray& ray) const {
    Vector3 L = point - ray.getOrigin();
    float radius2 = radius * radius;
    float tca = L * ray.getDirection();
    if (tca < 0) {
        return std::numeric_limits<float>::infinity();
    }
    float d2 = (L * L) - (tca * tca);
    if (d2 > radius2) {
        return std::numeric_limits<float>::infinity();
    }
    float thc = sqrt(radius2 - d2);
    float t0 = tca - thc;
    float t1 = tca + thc;
    if (t0 > t1) {
        std::swap(t0, t1);
    }

    if (t0 < 0) {
        t0 = t1; // if t0 is negative, let's use t1 instead
        if (t0 < 0) {
            return std::numeric_limits<float>::infinity(); // both t0 and t1 are negative
        }
    }

    float t = t0;

    return t;
}

Vector3 Sphere::computeNormal(const Vector3& pos) const {
    return (pos - point).unitVector();
}

Sphere::~Sphere()
{
    //dtor
}
