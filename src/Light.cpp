#include "Vector3.h"
#include "Light.h"

Light::Light(const Vector3 _position, const Vector3 _color)
: position(_position), color(_color)
{
    //ctor
}

Light::~Light()
{
    //dtor
}
