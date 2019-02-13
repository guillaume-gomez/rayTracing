#include "Box.h"
#include <math.h>

#include <limits>

Box::Box(Vector3 _point, Vector3 _color, float _specular, float _lambert, float _ambiant, Vector3 _vmin, Vector3 _vmax)
: point(_point), color(_color), specular(_specular), lambert(_lambert), ambiant(_ambiant), type("Box")
{
    bounds[0] = _vmin;
    bounds[1] = _vmax;
}

Box::Box(const Box& original)
: point(original.point), color(original.color), specular(original.specular), lambert(original.lambert), ambiant(original.ambiant), type("Box")
{
    bounds[0] = _vmin;
    bounds[1] = _vmax;
}

float Box::intersect(const Ray& ray) const {
    float tmin = (bounds[ray.getSign()[0]].x - ray.getOrigin().x) * ray.getInverseDirection().x; 
    float tmax = (bounds[1-ray.getSign()[0]].x - ray.getOrigin().x) * ray.getInverseDirection().x; 
    float tymin = (bounds[ray.getSign()[1]].y - ray.getOrigin().y) * ray.getInverseDirection().y; 
    float tymax = (bounds[1-ray.getSign()[1]].y - ray.getOrigin().y) * ray.getInverseDirection().y; 
 
    if ((tmin > tymax) || (tymin > tmax)) {
        return std::numeric_limits<float>::infinity();
    }

    if (tymin > tmin) {
        tmin = tymin;
    }

    if (tymax < tmax) {
        tmax = tymax;
    }
 
    float tzmin = (bounds[ray.getSign()[2]].z - ray.getOrigin().z) * ray.getInverseDirection().z; 
    float tzmax = (bounds[1-ray.getSign()[2]].z - ray.getOrigin().z) * ray.getInverseDirection().z; 
 
    if ((tmin > tzmax) || (tzmin > tmax)) {
        return std::numeric_limits<float>::infinity();
    }
    if (tzmin > tmin) {
        tmin = tzmin; 
    }
    if (tzmax < tmax) {
        tmax = tzmax; 
    }
 
    return tmin;
}

Vector3 Box::computeNormal(const Vector3& pos) const {
    return Vector3(0.0f, 0.0f, 0.0f);
}

Box::~Box()
{
    //dtor
}
