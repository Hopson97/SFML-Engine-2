#include "Application.h"

#include "States/SPlaying.h"

Application::Application(std::string&& appName)
:   m_window    ({1280, 720}, std::move(appName))
{
    m_window.setFramerateLimit(60);

    pushState<StatePlaying>(*this);
}

void Application::runMainLoop()
{


    while (m_window.isOpen())
    {
        float dt;
        handleEvents();
        m_window.clear();

        currentState().handleInput();
        currentState().update(dt);
        currentState().fixedUpdate(dt);
        currentState().draw(m_window);


        m_window.display();
    }
}

void Application::handleEvents()
{
    sf::Event e;
    while (m_window.pollEvent(e))
    {
        currentState().handleEvent(e);
        switch (e.type)
        {
            case sf::Event::Closed:
                m_window.close();
                break;

            default:
                break;
        }
    }
}


StateBase& Application::currentState()
{
    if (m_states.empty())
    {
        throw std::out_of_range("Tried to access game state, but there are none!");
    }
    return *m_states.back();
}
