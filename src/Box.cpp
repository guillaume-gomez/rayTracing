#include "Box.h"


Box::Box(Vector3 _point, Vector3 _color, float _specular, float _lambert, float _ambiant, Vector3 _vmin, Vector3 _vmax)
: point(_point), color(_color), specular(_specular), lambert(_lambert), ambiant(_ambiant), vmin(_vmin), vmax(_vmax), type("Box")
{
    //ctor
}

Box::Box(const Box& original)
: point(original.point), color(original.color), specular(original.specular), lambert(original.lambert), ambiant(original.ambiant), vmin(original.vmin), vmax(original.vmax), type("Box")
{

}

float Box::intersect(const Ray& ray) const {
    return 0.0f;
}

Vector3 Box::computeNormal(const Vector3& pos) const {
    return Vector3(0.0f, 0.0f, 0.0f);
}

Box::~Box()
{
    //dtor
}
