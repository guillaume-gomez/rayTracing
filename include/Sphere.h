#ifndef SPHERE_H
#define SPHERE_H

#include "SceneObject.h"

class Sphere : public SceneObject
{
    public:
        Sphere(Vector3 point = Vector3(), Vector3 color = Vector3(), float specular = 0.0f, float lambert = 0.0f, float ambiant = 0.0f, float radius = 0.0f);
        Sphere(const Sphere& copy);
        float intersect(const Ray& ray) const;
        virtual const Vector3 computeNormal(const Vector3& pos) const;
        virtual ~Sphere();
    protected:
        float radius;
};

#endif // SPHERE_H
