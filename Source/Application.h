#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "States/SBase.h"

class Application
{
    public:
        Application(std::string&& appName);

        void runMainLoop();

        template<typename T, typename... Args>
        void pushState(Args&&... args)
        {
            m_states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
        }

    private:
        void handleEvents();
        StateBase& currentState();


        std::vector<std::unique_ptr<StateBase>> m_states;

        sf::RenderWindow m_window;
};

#endif // APPLICATION_H
