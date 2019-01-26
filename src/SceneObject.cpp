#include "Vector3.h"
#include "SceneObject.h"

#include <string>

SceneObject::SceneObject(Vector3 _point, Vector3 _color, float _specular, float _lambert, float _ambiant)
: point(_point), color(_color), specular(_specular), lambert(_lambert), ambiant(_ambiant), type("SceneObject")
{
    //ctor
}

SceneObject::SceneObject(const SceneObject& original)
: point(original.point), color(original.color), specular(original.specular), lambert(original.lambert), ambiant(original.ambiant), type("SceneObject")
{

}

SceneObject::~SceneObject()
{
    //dtor
}
