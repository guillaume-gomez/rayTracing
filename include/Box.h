#ifndef Box_H
#define Box_H

#include "SceneObject.h"

class Box : public SceneObject
{
    public:
        Box(Vector3 point = Vector3(), Color color = Color(), float specular = 0.0f, float lambert = 0.0f, float ambiant = 0.0f, Vector3 vmin = Vector3(), Vector3 vmax = Vector3());
        Box(const Box& original);
        virtual ~Box();
        float intersect(const Ray& ray) const;
        Vector3 const computeNormal(const Vector3& pos) const;
    protected:
        Vector3 bounds[2];
};

#endif // Box_H
