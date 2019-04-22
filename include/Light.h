#ifndef LIGHT_H
#define LIGHT_H

#include "SceneObject.h"

class Light
{
    public:
        Light(const Vector3 position, const Vector3 color = Vector3(255.f, 255.f, 255.f), float intensity = 1.0f);
        virtual ~Light();
        Vector3 getPosition() const { return position; };
        Vector3 getColor() const { return color; };
        float getIntensity() const { return intensity; };
    private:
        Vector3 position;
        Vector3 color;
        float intensity;
};

#endif // LIGHT_H
