#ifndef Box_H
#define Box_H

#include "SceneObject.h"

class Box : public SceneObject
{
    public:
        Box(Vector3 point = Vector3(), Vector3 color = Vector3(), float specular = 0.0f, float lambert = 0.0f, float ambiant = 0.0f, Vector3 vmin, Vector3 vmax);
        Box(const Box& original);
        virtual ~Box();
        float intersect(const Ray& ray) const;
        virtual Vector3 computeNormal(const Vector3& pos) const;
    protected:
        Vector3 vmin;
        Vector3 vmax;
};

#endif // Box_H
