#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <string>
#include "Vector3.h"

class SceneObject
{
    public:
        SceneObject(Vector3 point = Vector3(), Vector3 color = Vector3(), float specular = 0.0f, float lambert = 0.0f, float ambiant = 0.0f);
        virtual ~SceneObject();
    protected:
        std::string type;
        Vector3 point;
        Vector3 color;
        float specular;
        float lambert;
        float ambiant;
};

#endif // SCENEOBJECT_H
