#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "lodepng.h"

#include "Scene.h"
#include "Sphere.h"
#include "Plane.h"

using namespace std;

Vector3 randomVector() {

    float x = 1 + std::rand()/((RAND_MAX + 1u)/255);
    float y = 1 + std::rand()/((RAND_MAX + 1u)/255);
    float z = 1 + std::rand()/((RAND_MAX + 1u)/255);
    return Vector3(x, y, z);
}

int main()
{
    std::srand(std::time(NULL));

    float width = 640.0f;
    float height = 480.0f;
    Camera camera = Camera(Vector3(0.0f, 0.0f, -3.0f), Vector3(0.0f, 0.0f, 10.0f));
    Light light = Light(Vector3(-30.0f, -10.0f, -20.0f));

    Sphere s1 = Sphere(Vector3(0.0f, 0.0f, 11.0f), Vector3(155.0f, 200.0f, 155.0f), 0.2f, 0.7f, 0.1f, 1.0f);
    Sphere s2 = Sphere(Vector3(-2.0f, 1.0f, 9.0f), Vector3(155.0f, 155.0f, 155.0f), 0.1f, 0.9f, 0.0f, 1.0f);
    Sphere s3 = Sphere(Vector3(-1.5f, 2.0f, 7.0f), Vector3(10.0f, 255.0f, 255.0f), 0.2f, 0.7f, 0.1f, 1.0f);
    Plane p = Plane(Vector3(0.0f, 0.0f, 13.0f), randomVector(), 0.2f, 0.7f, 0.1f, Vector3(0.0f, 0.0f, 1.0f));
    Scene scene = Scene(width, height, camera);
    scene.addLight(light);
    scene.addObject(&p);
    scene.addObject(&s1);

    scene.addObject(&s2);
    scene.addObject(&s3);


    std::vector<unsigned char> image = scene.render();
    std::string filename = "output1.png";
    unsigned error = lodepng::encode(filename, image, width, height);
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;

    return 0;
}
