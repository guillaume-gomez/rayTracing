#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <string>

#include "Ray.h"
#include "Vector3.h"

class SceneObject
{
    public:
        SceneObject(Vector3 point = Vector3(), Vector3 color = Vector3(), float specular = 0.0f, float lambert = 0.0f, float ambiant = 0.0f);
        SceneObject(const SceneObject& original);
        virtual float intersect(const Ray& ray) const = 0;
        virtual const Vector3 computeNormal(const Vector3& pos) const = 0;
        virtual ~SceneObject();
        const Vector3 getColor() const { return color; };
        const Vector3 getPoint() const { return point; };
        const float getSpecular() const { return specular; };
        const float getLambert() const { return lambert; };
        const float getAmbiant() const { return ambiant; };
        const std::string getType() const { return type; };
    protected:
        std::string type;
        Vector3 point;
        Vector3 color;
        float specular;
        float lambert;
        float ambiant;
};

#endif // SCENEOBJECT_H
