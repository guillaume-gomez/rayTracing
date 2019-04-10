#ifndef DISK_H
#define DISK_H

#include <Plane.h>


class Disk : public Plane
{
    public:
        Disk(Vector3 point = Vector3(), Vector3 color = Vector3(), float specular = 0.0f, float lambert = 0.0f, float ambiant = 0.0f, Vector3 normal = Vector3(), float radius = 0.0f);
        Disk(const Disk& original);
        virtual float intersect(const Ray& ray) const;
        virtual const Vector3 computeNormal(const Vector3& pos) const;
        virtual ~Disk();
    protected:
        float radius;
};

#endif // DISK_H
