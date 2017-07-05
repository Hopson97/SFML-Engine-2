#ifndef RESOURCEHOLDER_INCLUDED
#define RESOURCEHOLDER_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.h"

struct ResourceHolder
{
    static ResourceHolder& get()
    {
        static ResourceHolder res;
        return res;
    }

    ResourceHolder() noexcept
    :   textures        ("res/textures/",   "png")
    ,   fonts           ("res/fonts/",      "ttf")
    ,   soundBuffers    ("res/sfx",         "ogg")
    { }

    ResourceManager<sf::Texture>        textures;
    ResourceManager<sf::Font>           fonts;
    ResourceManager<sf::SoundBuffer>    soundBuffers;

};

#endif // RESOURCEHOLDER_INCLUDED
