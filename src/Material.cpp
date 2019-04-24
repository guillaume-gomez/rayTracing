#include "Material.h"

Material::Material( Color _specularColor,
                    Color _diffuseColor,
                    Color _ambientColor,
                    Color _selfIllumColor,
                    float _shininess,
                    float _shinestrength,
                    float _transmittivity,
                    float _reflectivity,
                    std::string _name
                )
: specularColor(_specularColor),
  diffuseColor(_diffuseColor),
  ambientColor(_ambientColor),
  selfIllumColor(_selfIllumColor),
  shininess(_shininess),
  shinestrength(_shinestrength),
  transmittivity(_transmittivity),
  reflectivity(_reflectivity),
  name(_name)
{
    //ctor
}

Material::~Material()
{
    //dtor
}
