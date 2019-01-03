#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "SceneObject.h"
#include "Light.h"
#include "Camera.h"

class Scene
{
    public:
        Scene(const Camera& camera);
        void addLight(const Light& light);
        void addObject(const SceneObject& object);
        virtual ~Scene();
    private:
        Camera camera;
        std::vector<Light> lights;
        std::vector<SceneObject> objects;
};

#endif // SCENE_H
