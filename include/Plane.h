#ifndef PLANE_H
#define PLANE_H

#include "SceneObject.h"

class Plane : public SceneObject
{
    public:
        Plane(Vector3 point = Vector3(), Vector3 color = Vector3(), float specular = 0.0f, float lambert = 0.0f, float ambiant = 0.0f, Vector3 normal = Vector3());
        Plane(const Plane& original);
        virtual ~Plane();
        float intersect(const Ray& ray) const;
        Vector3 computeNormal(const Vector3& pos) const;
    protected:
        Vector3 normal;
};

#endif // PLANE_H
