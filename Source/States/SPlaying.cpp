#include "SPlaying.h"

#include "../ResourceManager/ResourceHolder.h"



StatePlaying::StatePlaying(Application& application)
:   StateBase (application)
{
    m_sprite.setTexture(&ResourceHolder::getTexure("test"));
    m_sprite.setSize({32, 32});
}

void StatePlaying::handleInput()
{

}

void StatePlaying::handleEvent(sf::Event e)
{

}

void StatePlaying::update(float dt)
{

}

void StatePlaying::fixedUpdate(float dt)
{

}

void StatePlaying::draw(sf::RenderWindow& window)
{

    window.draw(m_sprite);
}
