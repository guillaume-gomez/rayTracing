#include "Ray.h"
#include "Scene.h"

#include <cmath>
#include <limits>

#include <iostream>

Scene::Scene(float _width, float _height, Camera& _camera, int _level)
: width(_width), height(_height), camera(_camera), needUpdate(true), level(_level)
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
    needUpdate = false;
    return image;
}

Vector3 Scene::surface(Ray& ray, const SceneObject* object, Vector3& pointAtTime, const Vector3 normal, int depth) {
    Vector3 zero = Vector3();
    Vector3 objectColor = object->getColor();
    float lambertAmount = 0;

    // **[Lambert shading](http://en.wikipedia.org/wiki/Lambertian_reflectance)**
    // is our pretty shading, which shows gradations from the most lit point on
    // the object to the least.
    if (object->getLambert()) {
        for (std::vector<Light>::iterator light = lights.begin(); light != lights.end(); ++light) {
            Vector3 lightPoint = light->getPosition();
            // First: can we see the light? If not, this is a shadowy area
            // and it gets no light from the lambert shading process.
            if (!isLightVisible(pointAtTime, lightPoint)) {
                continue;
            }
            // Otherwise, calculate the lambertian reflectance, which
            // essentially is a 'diffuse' lighting system - direct light
            // is bright, and from there, less direct light is gradually,
            // beautifully, less light.
            float contribution = (lightPoint - pointAtTime).unitVector() * normal;
            // sometimes this formula can return negatives, so we check:
            // we only want positive values for lighting.
            if (contribution > 0) {
                lambertAmount += contribution;
            }
        }
    }

    // **[Specular](https://en.wikipedia.org/wiki/Specular_reflection)** is a fancy word for 'reflective': rays that hit objects
    // with specular surfaces bounce off and acquire the colors of other objects
    // they bounce into.
    if (object->getSpecular()) {
        // This is basically the same thing as what we did in `render()`, just
        // instead of looking from the viewpoint of the camera, we're looking
        // from a point on the surface of a shiny object, seeing what it sees
        // and making that part of a reflection.
        Ray reflectedRay = Ray(pointAtTime, Vector3::reflectThrough(ray.getDirection(), normal));
        Vector3 reflectedColor = trace(reflectedRay, ++depth);
        if (reflectedColor != Vector3(255.f, 255.f, 255.f)) {
            Vector3 specularVector = reflectedColor * object->getSpecular();
            zero = zero + specularVector;
        }
    }

    // lambert should never 'blow out' the lighting of an object,
    // even if the ray bounces between a lot of things and hits lights
    lambertAmount = fmin(1, lambertAmount);

    // **Ambient** colors shine bright regardless of whether there's a light visible -
    // a circle with a totally ambient blue color will always just be a flat blue
    // circle.
    return Vector3::add3(zero, object->getColor() * lambertAmount * object->getLambert(), object->getColor() * object->getAmbiant());
}


// Vector3 Scene::trace(Ray& ray, int depth) {
//     if (depth > level) {
//         return Vector3(255.f, 255.f, 255.f);
//     }

//     distObject distObject = intersectScene(ray);
//     const SceneObject* object = distObject.object;
//     if(object == NULL) {
//         return backgroundColor();
//     }
//     // The `pointAtTime` is another way of saying the 'intersection point'
//     // of this ray into this object. We compute this by simply taking
//     // the direction of the ray and making it as long as the distance
//     // returned by the intersection check.
//     Vector3 pointAtTime = ray.getOrigin() + (ray.getDirection() * distObject.distance);


//     return surface(ray, object, pointAtTime, object->computeNormal(pointAtTime), depth);

//     //return distObject.object->getColor();

// }

Vector3 Scene::trace(Ray& viewRay, int depth) {
    Vector3 finalColor = backgroundColor();

    distObject distObject1 = intersectScene(viewRay);
    const SceneObject* object1 = distObject1.object;

    if(object1 == NULL) {
        return backgroundColor();
    }

    bool lightBlocked = false;
    for (std::vector<Light>::iterator light = lights.begin(); light != lights.end(); ++light) {
        lightBlocked = false;
        Vector3 intersectObject = viewRay.getOrigin() + (viewRay.getDirection() * distObject1.distance);
        Vector3 lightVec = intersectObject - light->getPosition();
        float lightToObjDist = lightVec.magnitude();
        lightVec.normalize();

        Ray lightRay = Ray(light->getPosition(), lightVec);

        distObject distObject2 = intersectScene(lightRay);
        const SceneObject* object2 = distObject2.object;

        if(object1 != object2) {
            Vector3 intersectionLight = lightRay.getOrigin() + (lightRay.getDirection() * distObject2.distance);
            Vector3 lightToInterVec = intersectionLight - light->getPosition();
            float lightToInterDist = lightToInterVec.magnitude();
            if(lightToInterDist < lightToObjDist) {
                lightBlocked = true;
            }
        }

        if(!lightBlocked) {
            finalColor += getLightAt(intersectObject, object1, *light);
        }
    }

    return Vector3(std::min(finalColor.x, 255.0f), std::min(finalColor.y, 255.0f), std::min(finalColor.z, 255.0f));

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

Vector3 Scene::getLightAt(const Vector3& intersectionPoint, const SceneObject* object, const Light& light) {
    Vector3 normal = object->computeNormal(intersectionPoint);
    Vector3 lightVector = Vector3(intersectionPoint - light.getPosition()).normalize();
    Vector3 invertLightVector = Vector3(-lightVector.x, -lightVector.y, - lightVector.z);
    float angle = normal * invertLightVector;
    if(angle <= 0) {
        return backgroundColor();
    }
    const Vector3 objectColor = object->getColor();
    const Vector3 lightColor = light.getColor();
    return Vector3(objectColor.x * lightColor.x, objectColor.y * lightColor.y, objectColor.z * lightColor.z) * angle;
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
