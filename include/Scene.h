#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "SceneObject.h"
#include "Ray.h"
#include "Light.h"
#include "Camera.h"

struct distObject {
    float distance;
    const SceneObject* object;
};

class Scene : public IObserver
{
    public:
        Scene(float width, float height, Camera& camera);
        void addLight(const Light& light);
        void addObject(const SceneObject* object);
        std::vector<unsigned char> render();
        distObject intersectScene(const Ray& ray);
        const float getWidth() const { return width; };
        const float getHeight() const { return height; };
        Camera& getCamera() { return camera; };
        const bool IsneededUpdate() { return needUpdate; };
        virtual ~Scene();
        void update(std::string data);
    private:
        float width;
        float height;
        bool needUpdate;
        Camera& camera;
        std::vector<Light> lights;
        std::vector<const SceneObject*> objects;
        std::vector<unsigned char> image;

        Vector3 trace(Ray& ray, int depth);
        bool isLightVisible(const Vector3 point, const Light light);
        Vector3 surface(Ray& ray, SceneObject& object, Vector3& pointAtTime, Vector3& normal, int depth);
};

#endif // SCENE_H
