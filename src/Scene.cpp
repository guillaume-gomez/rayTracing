#include "Ray.h"
#include "Scene.h"

#include <math.h>
#include <limits>

// #include <iostream>

Scene::Scene(float _width, float _height, const Camera& _camera)
: width(_width), height(_height), camera(_camera)
{
    //ctor
}

void Scene::addLight(const Light& light) {
    lights.push_back(light);
}

void Scene::addObject(const SceneObject* object) {
    objects.push_back(object);
}

std::vector<unsigned char> Scene::render() {
    Vector3 eyeVector = camera.eyeVector();
    Vector3 up = Vector3(0.0f, 1.0f, 0.0f);

    Vector3 vpRight = (Vector3::crossProduct(eyeVector, up)).unitVector();
    Vector3 vpUp = (Vector3::crossProduct(vpRight, eyeVector)).unitVector();

    float fovRadians = M_PI * (camera.getFov() / 2.0f) / 180.f;
    float heightWidthRatio = height / width;
    float halfWidth = tan(fovRadians);
    float halfHeight = heightWidthRatio * halfWidth;
    float camerawidth = halfWidth * 2.0f;
    float cameraheight = halfHeight * 2.0f;
    float pixelWidth = camerawidth / (width - 1.0f);
    float pixelHeight = cameraheight / (height - 1.0f);

    unsigned int index, color;
    Ray ray = Ray(camera.getPoint());

    std::vector<unsigned char> image;
    image.resize(width * height * 4);
    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {

            // turn the raw pixel `x` and `y` values into values from -1 to 1
            // and use these values to scale the facing-right and facing-up
            // vectors so that we generate versions of the `eyeVector` that are
            // skewed in each necessary direction.
            Vector3 xcomp = vpRight * ( (x * pixelWidth) - halfWidth);
            Vector3 ycomp = vpUp    * ( (y * pixelHeight) - halfHeight);


            Vector3 rayDirection = (eyeVector + xcomp + ycomp).unitVector();
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
        return Vector3(255.f, 200.0f, 10.f);
    }
    return distObject.object->getColor();

    // return Vector3(255.f, 0.0f, 200.f);
}

distObject Scene::intersectScene(const Ray& ray) {
    // The base case is that it hits nothing, and travels for `Infinity`
    distObject closest;
    closest.distance = std::numeric_limits<double>::infinity();
    closest.object = NULL;
    // But for each object, we check whether it has any intersection,
    // and compare that intersection - is it closer than `Infinity` at first,
    // and then is it closer than other objects that have been hit?
    for (unsigned int i = 0; i < objects.size(); i++) {
        const SceneObject* object = objects[i];
        float dist = object->intersect(ray);
        if (dist != NULL && dist < closest.distance) {
            closest.distance = dist;
            closest.object   = object;
        }
    }
    return closest;
}

bool Scene::isLightVisible(const Vector3 point, const Light light) {
    Ray ray = Ray(point, (point - light).unitVector());
    distObject distObject = intersectScene(ray);
    return distObject.distance > -0.005;
}

Scene::~Scene()
{
    //dtor
}
