#include <iostream>
#include <string>
#include "lodepng.h"

#include "Scene.h"
#include "Sphere.h"

using namespace std;

int main()
{
    float width = 640.0f;
    float height = 480.0f;
    Camera camera = Camera(Vector3(0.0f, 1.8f, 10.0f), Vector3(0.0f, 3.0f, 0.0f));
    Light light = Light(Vector3(-30.0f, -10.0f, -20.0f));

    Sphere s1 = Sphere(Vector3(0.0f, 3.5f, -3.0f), Vector3(155.0f, 200.0f, 155.0f), 0.2f, 0.7f, 0.1f, 3.0f);
    Sphere s2 = Sphere(Vector3(-4.0f, 2.0f, -1.0f), Vector3(155.0f, 155.0f, 155.0f), 0.1f, 0.9f, 0.0f, 0.2f);
    Sphere s3 = Sphere(Vector3(-4.0f, 3.0f, -1.0f), Vector3(255.0f, 255.0f, 255.0f), 0.2f, 0.7f, 0.1f, 0.1f);

    Scene scene = Scene(width, height, camera);
    scene.addLight(light);
    scene.addObject(&s1);
    scene.addObject(&s2);
    scene.addObject(&s3);


    std::vector<unsigned char> image = scene.render();
    std::string filename = "output.png";
    unsigned error = lodepng::encode(filename, image, width, height);
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;

    return 0;
}
