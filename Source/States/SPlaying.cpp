#include "SPlaying.h"

#include "../ResourceManager/ResourceHolder.h"

#include "../Animation.h"

Animation animation;

StatePlaying::StatePlaying(Application& application)
:   StateBase (application)
{
    m_sprite.setTexture(&ResourceHolder::getTexure("test"));
    m_sprite.setSize({32, 32});

    animation.addFrames({16, 16}, {0, 0}, 4, sf::seconds(0.5));
}

void StatePlaying::handleInput()
{

}

void StatePlaying::handleEvent(sf::Event e)
{

}

void StatePlaying::update(float dt)
{
    m_sprite.setTextureRect(animation.getFrame());
}

void StatePlaying::fixedUpdate(float dt)
{

}

void StatePlaying::draw(sf::RenderWindow& window)
{

    window.draw(m_sprite);
}
