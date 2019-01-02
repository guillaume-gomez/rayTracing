#include "Sphere.h"

Sphere::Sphere(Vector3 _point, Vector3 _color, float _specular, float _lambert, float _ambiant, float _radius)
: SceneObject(_point, _color, _specular, _lambert, _ambiant), radius(_radius)
{
    type = "Sphere";
}

Sphere::~Sphere()
{
    //dtor
}
