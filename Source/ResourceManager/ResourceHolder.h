#ifndef RESOURCEHOLDER_INCLUDED
#define RESOURCEHOLDER_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.h"

class ResourceHolder
{
    public:
        static ResourceHolder& get()
        {
            static ResourceHolder res;
            return res;
        }

        ResourceManager<sf::Texture>        textures;
        ResourceManager<sf::Font>           fonts;
        ResourceManager<sf::SoundBuffer>    soundBuffers;

    private:
        ResourceHolder() noexcept
        :   textures        ("res/textures/",   "png")
        ,   fonts           ("res/fonts/",      "ttf")
        ,   soundBuffers    ("res/sfx",         "ogg")
        { }
};

#endif // RESOURCEHOLDER_INCLUDED
