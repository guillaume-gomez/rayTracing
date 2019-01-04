#include "Scene.h"


Scene::Scene(const Camera& _camera)
:camera(_camera)
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
    // TODO
}

Scene::~Scene()
{
    //dtor
}
