#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "lodepng.h"

#include "Scene.h"
#include "Sphere.h"
#include "Plane.h"
#include "Disk.h"
#include "Triangle.h"
#include "Box.h"
#include "Window.h"

using namespace std;

Color randomVector() {

    float x = 1 + std::rand()/((RAND_MAX + 1u)/255);
    float y = 1 + std::rand()/((RAND_MAX + 1u)/255);
    float z = 1 + std::rand()/((RAND_MAX + 1u)/255);
    return Color(x, y, z);
}

std::string gen_random_filename(const int len) {
    std:string result = std::string();
    result.resize(len);
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        result[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return result + ".png";
}

int main(int argc, char *argv[])
{
    std::srand(std::time(NULL));

    float width = 640.0f;
    float height = 480.0f;
    Camera camera = Camera(Vector3(0.0f, 3.0f, -15.0f), Vector3(0.0f, 0.0f, 10.0f));
    Light light = Light(Vector3(3.0f, 3.0f, 0.0f), Color(255.0f, 0.0f, 0.0f));
    Light light2 = Light(Vector3(-3.0f, 3.0f, 0.0f), Color(0.0f, 0.0f, 255.0f));
    Light light3 = Light(Vector3(0.0f, 0.0f, 0.0f), Color(0.0f, 255.0f, 255.0f));

    Sphere s1 = Sphere(Vector3(0.0f, 3.0f, 8.0f), Color(255.0f, 255.0f, 255.0f), 0.5f, 0.0f, 0.5f, 2.0f);
    Sphere s2 = Sphere(Vector3( -4.5f, 2.0f, 10.0f), Color(0.0f, 255.0f, 255.0f), 0.5f, 0.0f, 0.5f, 2.0f);
    Sphere s3 = Sphere(Vector3( 4.5f, 4.0f, 6.0f), Color(255.0f, 0.0f, 255.0f), 0.5f, 0.0f, 0.5f, 2.0f);

    Plane p = Plane(Vector3(0.0f, 6.0f, 8.0f), Color(255.0f, 0.0f, 255.0f), 0.2f, 0.7f, 0.1f, Vector3(0.0f, -1.0f, 0.0f));
    Disk d = Disk(Vector3(0.0f, 0.0f, 10.0f), randomVector(), 0.5f, 0.8f, 0.2f, Vector3(0.0f, 0.0f, -1.0f), 10.0f);
    Triangle t = Triangle(Vector3(0.0f, 0.0f, 8.0f), randomVector(), 0.5f, 0.8f, 0.2f, Vector3(-2.0f, 0.0f, 5.0f), Vector3(2.f, 0.0f, 5.0f), Vector3(0.0f, 1.0f, 5.0f));
    Box b = Box(Vector3(0.0f, 0.0f, 0.0f), Color(255.0f, 255.0f, 255.0f), 0.5f, 0.8f, 0.2f, Vector3(-2.0f, -2.0f, 5.0f), Vector3(2.f, 2.0f, 15.0f));

    Scene scene = Scene(width, height, camera, 1);

    scene.addLight(light);
    scene.addLight(light2);
    //scene.addLight(light3);
    scene.addObject(&s1);
    scene.addObject(&s2);
    scene.addObject(&s3);

    //scene.addObject(&b);
    scene.addObject(&p);
    scene.addObject(&d);
    //scene.addObject(&t);

    std::vector<unsigned char> image = scene.render();
    std::string filename = (argc >= 2 && argv[1]) ? std::string(argv[1]) : "renders/" + gen_random_filename(15);
    std::cout << "output filename '" << filename << "'" << std::endl;

    unsigned error = lodepng::encode(filename, image, width, height);
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;


    if(argc >= 3 && argv[2]) {
       Window window = Window(scene);
       window.display();
    }

    return 0;
}
