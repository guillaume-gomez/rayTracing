#include "Vector3.h"
#include "Light.h"

Light::Light(const Vector3 _position, const Vector3 _color, float _intensity)
: position(_position), color(_color), intensity(_intensity)
{
    //ctor
}


Light::~Light()
{
    //dtor
}
