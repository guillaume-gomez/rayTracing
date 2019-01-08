#include "Scene.h"

#include <math.h>

Scene::Scene(float _width, float _height, const Camera& _camera)
: width(_width), height(_height), camera(_camera)
{
    //ctor
}

void Scene::addLight(const Light& light) {
    lights.push_back(light);
}

void Scene::addObject(const SceneObject& object) {
    objects.push_back(object);
}

void Scene::render() {
    Vector3 eyeVector = camera.eyeVector();
    Vector3 up = Vector3(0.0f, 1.0f, 0.0f);

    Vector3 vpRight = (Vector3::crossProduct(eyeVector, up)).unitVector();
    Vector3 vpUp = (Vector3::crossProduct(vpRight, eyeVector)).unitVector();

    const fovRadians = M_PI * (camera.getFov() / 2) / 180,
    heightWidthRatio = height / width,
    halfWidth = Math.tan(fovRadians),
    halfHeight = heightWidthRatio * halfWidth,
    camerawidth = halfWidth * 2,
    cameraheight = halfHeight * 2,
    pixelWidth = camerawidth / (width - 1),
    pixelHeight = cameraheight / (height - 1);


}

Scene::~Scene()
{
    //dtor
}
