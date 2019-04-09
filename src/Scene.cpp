#include "Ray.h"
#include "Scene.h"

#include <math.h>
#include <limits>

#include <iostream>

Scene::Scene(float _width, float _height, Camera& _camera)
: width(_width), height(_height), camera(_camera), needUpdate(true)
{
    camera.computeViewPlane(width, height);
    camera.addObserver(this);

    image.resize(width * height * 4);
}

void Scene::addLight(const Light& light) {
    lights.push_back(light);
}

void Scene::addObject(const SceneObject* object) {
    objects.push_back(object);
}

std::vector<unsigned char> Scene::render() {
    if(!needUpdate) {
        return image;
    }

    unsigned int index, color;
    Ray ray = Ray(camera.getPoint());
    std::cout << camera.getPoint() << std::endl;
    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {

            // Affichage de notre "barre de progression" ;)
            if (x==0 && y==0.25f*height) {
                std::cout << "25 percent completed !\n" << std::endl;
            }

            if (x==0 && y==0.5f*height) {
                std::cout << "50 percent completed !\n" << std::endl;
            }

            if (x==0 && y==0.75f*height) {
                std::cout << "75 percent completed !\n" << std::endl;
            }

            if (x==0 && y==height-1) {
                std::cout << "100 percent completed !\n" << std::endl;
            }

            Vector3 rayDirection = camera.calcDirVec(float(x), float(y), width, height); //(eyeVector + xcomp + ycomp).unitVector();
            ray.setDirection(rayDirection);

            // use the vector generated to raytrace the scene, returning a color
            // as a `{x, y, z}` vector of RGB values
            Vector3 color = trace(ray, 0);
            float index = (x * 4) + (y * width * 4);
            image[index + 0] = color.x;
            image[index + 1] = color.y;
            image[index + 2] = color.z;
            image[index + 3] = 255;
        }
    }
    return image;
}

Vector3 Scene::trace(Ray& ray, float depth) {
    if (depth > 3) {
        return Vector3(255.f, 255.f, 255.5f);
    }

    distObject distObject = intersectScene(ray);
    if(distObject.object == NULL) {
        return Vector3(255.f, 100.0f, 100.f);
    }
    return distObject.object->getColor();

    // return Vector3(255.f, 0.0f, 200.f);
}

distObject Scene::intersectScene(const Ray& ray) {
    // The base case is that it hits nothing, and travels for `Infinity`
    distObject closest;
    closest.distance = std::numeric_limits<float>::infinity();
    closest.object = NULL;
    // But for each object, we check whether it has any intersection,
    // and compare that intersection - is it closer than `Infinity` at first,
    // and then is it closer than other objects that have been hit?
    for (std::vector<const SceneObject*>::iterator object = objects.begin(); object != objects.end(); ++object) {
        float dist = (*object)->intersect(ray);
        if (dist != 0 && dist < closest.distance) {
            closest.distance = dist;
            closest.object   = *object;
        }
    }
    return closest;
}

bool Scene::isLightVisible(const Vector3 point, const Light light) {
    Ray ray = Ray(point, (point - light.getPosition()).unitVector());
    distObject distObject = intersectScene(ray);
    return distObject.distance > -0.005;
}

void Scene::update(std::string data) {
    std::cout << "message ->" << data << std::endl;
    needUpdate = true;
}

Scene::~Scene()
{
    //dtor
}
