#include "Window.h"

float OFFSET = 0.01f;

Window::Window(Scene& _scene):
scene(_scene)
{
    width = scene.getWidth();
    height = scene.getHeight();
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Ray Tracing View");
    pixels = new sf::Uint8[width * height * 4];
    texture = new sf::Texture();
    texture->create(width, height);
    sprite = new sf::Sprite(*texture);
}

void Window::updateBuffer() {
    std::vector<unsigned char> image = scene.render();
    //if (scene.IsneededUpdate()) {
        //std::cout << "rerender" << std::endl;
        for(register int i = 0; i < image.size(); i += 4) {
            pixels[i] = image[i];
            pixels[i + 1] = image[i + 1];
            pixels[i + 2] = image[i + 2];
            pixels[i + 3] = image[i + 3];
        }
        texture->update(pixels);
    //}
}


void Window::display() {
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window->close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                scene.getCamera().move(Vector3(-OFFSET, 0.0f, 0.0f));
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                scene.getCamera().move(Vector3(OFFSET, 0.0f, 0.0f));
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                scene.getCamera().move(Vector3(0.f, -OFFSET, 0.0f));
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                scene.getCamera().move(Vector3(0.f, OFFSET, 0.0f));
            }
        }
        updateBuffer();
        render();
    }
}

void Window::render() {
    window->clear();
    window->draw(*sprite);
    window->display();
}


Window::~Window()
{
    delete sprite;
    delete texture;
    delete pixels;
    delete window;
}
