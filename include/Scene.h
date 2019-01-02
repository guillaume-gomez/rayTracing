#ifndef SCENE_H
#define SCENE_H

#include <vector>

class Scene
{
    public:
        Scene();
        virtual ~Scene();
    private:
        Camera camera;
        std::vector<Light> lights;
        std::vector<SceneObject> objects;
};

#endif // SCENE_H
