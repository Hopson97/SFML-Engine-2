#ifndef SPLAYING_INCLUDED
#define SPLAYING_INCLUDED

#include "../Application.h"

#include "SBase.h"

class StatePlaying : public StateBase
{
    public:
        StatePlaying(Application& application);

        void handleInput    ();
        void handleEvent    (sf::Event e);
        void update         (float dt);
        void fixedUpdate    (float dt);
        void draw           (sf::RenderWindow& window);

    private:
        sf::RectangleShape m_sprite;
};

#endif // SPLAYING_INCLUDED
