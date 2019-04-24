#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color.h"

class Material
{
    public:
        Material( Color specularColor = Color(0.0f, 0.0f, 0.0f),
                  Color diffuseColor = Color(0.0f, 0.0f, 0.0f),
                  Color ambientColor = Color(0.0f, 0.0f, 0.0f),
                  Color selfIllumColor = Color(0.0f, 0.0f, 0.0f),
                  float shininess = 0.0f,
                  float shinestrength = 0.0f,
                  float transmittivity = 0.0f,
                  float reflectivity = 0.0f,
                  std::string name = "undefined type"
                );
        virtual ~Material();

    protected:
        Color  specularColor;
        Color  diffuseColor;
        Color  ambientColor;
        Color  selfIllumColor;
        float  shininess;
        float  shinestrength;
        float  transmittivity;
        float  reflectivity;
        std::string name;
};

#endif // MATERIAL_H
