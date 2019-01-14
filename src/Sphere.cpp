#include "Sphere.h"
#include <math.h>

Sphere::Sphere(Vector3 _point, Vector3 _color, float _specular, float _lambert, float _ambiant, float _radius)
: SceneObject(_point, _color, _specular, _lambert, _ambiant), radius(_radius)
{
    // Point attribute means center here
    type = "Sphere";
}

float Sphere::intersect(const Ray& ray) const {
    Vector3 rayOriginToCenter = point - ray.getOrigin();
    float rayT = rayOriginToCenter * ray.getDirection(); // dot product
    float rayOriginToCenterLength = rayOriginToCenter * rayOriginToCenter; // dot product
    float discriminant = (radius * radius) - rayOriginToCenterLength + (rayT * rayT);

    if(discriminant < 0) {
        return 0;
    } else {
        return rayOriginToCenterLength - sqrt(discriminant);
    }
}

Vector3 Sphere::computeNormal(const Vector3& pos) const {
    return (pos - point).unitVector();
}

Sphere::~Sphere()
{
    //dtor
}
