#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "SceneObject.h"

class Triangle : public SceneObject
{
    public:
        Triangle(Vector3 point = Vector3(), Vector3 color = Vector3(), float specular = 0.0f, float lambert = 0.0f, float ambiant = 0.0f, Vector3 a = Vector3(), Vector3 b = Vector3(), Vector3 c = Vector3());
        virtual ~Triangle();
        float intersect(const Ray& ray) const;
        Vector3 computeNormal(const Vector3& pos) const;
    protected:
        Vector3 a;
        Vector3 b;
        Vector3 c;
};

#endif // TRIANGLE_H
