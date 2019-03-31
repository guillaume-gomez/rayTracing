#include "Window.h"

Window::Window(Scene& scene)
{
    width = scene.getWidth();
    height = scene.getHeight();
    sf::RenderWindow window(sf::VideoMode(width, height), "Ray Tracing View");
    sf::Uint8 *pixels = new sf::Uint8[width * height * 4];
}

Window::~Window()
{
    //dtor
}
