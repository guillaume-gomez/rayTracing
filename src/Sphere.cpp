#include "Sphere.h"
#include <math.h>

Sphere::Sphere(Vector3 _point, Vector3 _color, float _specular, float _lambert, float _ambiant, float _radius)
: SceneObject(_point, _color, _specular, _lambert, _ambiant), radius(_radius)
{
    type = "Sphere";
}

float Sphere::intersect(const Ray& ray) const {
    Vector3 eyeToCenter = point - ray.getOrigin();
    Vector3 v = Vector3::crossProduct(eyeToCenter, ray.getDirection());
    Vector3 eoDot = Vector3::crossProduct(eyeToCenter, eyeToCenter);
    float lengthVEoDot = (eoDot + (v * v)).magnitude();
    float discriminant = (radius * radius) - lengthVEoDot;
    if(discriminant < 0) {
        return 0;
    } else {
        return v.magnitude() - sqrt(discriminant);
    }
}

Sphere::~Sphere()
{
    //dtor
}
