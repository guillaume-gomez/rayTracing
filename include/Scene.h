#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "SceneObject.h"
#include "Ray.h"
#include "Light.h"
#include "Camera.h"

struct distObject {
    double distance;
    const SceneObject* object;
};

class Scene
{
    public:
        Scene(float width, float height, const Camera& camera);
        void addLight(const Light& light);
        void addObject(const SceneObject* object);
        std::vector<unsigned char> render();
        distObject intersectScene(const Ray& ray);
        const float getWidth() const { return width; };
        const float getHeight() const { return height; };
        virtual ~Scene();
    private:
        float width;
        float height;
        Camera camera;
        std::vector<Light> lights;
        std::vector<const SceneObject*> objects;

        Vector3 trace(Ray& ray, float depth);
        bool isLightVisible(const Vector3 point, const Light light);
};

#endif // SCENE_H
