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
        Scene(float width, float height, Camera& camera, int level);
        void addLight(const Light& light);
        void addObject(const SceneObject* object);
        std::vector<unsigned char> render();
        distObject intersectScene(const Ray& ray);
        const float getWidth() const { return width; };
        const float getHeight() const { return height; };
        Camera& getCamera() { return camera; };
        const bool IsneededUpdate() { return needUpdate; };
        virtual ~Scene();
        const Vector3 backgroundColor() const { return Vector3(0.0f, 0.0f, 0.0f);};
        void update(std::string data);
    private:
        float width;
        float height;
        bool needUpdate;
        Camera& camera;
        std::vector<Light> lights;
        std::vector<const SceneObject*> objects;
        std::vector<unsigned char> image;
        int level;

        Vector3 trace(Ray& ray, int depth);
        bool isLightVisible(const Vector3 point, const Light light);
        Vector3 surface(Ray& ray, const SceneObject* object, Vector3& pointAtTime, const Vector3 normal, int depth);
        Vector3 getLightAt(const Vector3& intersectionPoint, const SceneObject* object, const Light& light);
};

#endif // SCENE_H
