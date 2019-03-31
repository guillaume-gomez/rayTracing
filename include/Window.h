#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Scene.h"

// todo singleton

class Window
{
    public:
        Window(Scene& scene);
        void render();
        virtual ~Window();

    protected:
        unsigned int width;
        unsigned int height;
        sf::RenderWindow *window;
        sf::Uint8 *pixels;
        sf::Sprite *sprite;
        sf::Texture *texture;
};

#endif // WINDOW_H
