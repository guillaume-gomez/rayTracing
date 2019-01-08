#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "SceneObject.h"
#include "Light.h"
#include "Camera.h"

class Scene
{
    public:
        Scene(float width, float height, const Camera& camera);
        void addLight(const Light& light);
        void addObject(const SceneObject& object);
        void render();
        const float getWidth() const { return width; };
        const float getHeight() const { return height; };
        virtual ~Scene();
    private:
        float width;
        float height;
        Camera camera;
        std::vector<Light> lights;
        std::vector<SceneObject> objects;
};

#endif // SCENE_H
