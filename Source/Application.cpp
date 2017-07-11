#include "Application.h"

#include "States/SPlaying.h"

#include <cstdint>
#include <iostream>

Application::Application(std::string&& appName)
:   m_window    ({1280, 720}, std::move(appName))
{
    m_window.setFramerateLimit(60);
    pushState<StatePlaying>(*this);
}


void Application::runMainLoop()
{
    constexpr uint32_t  TICKS_PER_FRAME = 30;
    const sf::Time      MS_PER_TICK     = sf::seconds((float)1 / (float)TICKS_PER_FRAME);

    uint32_t tickCount = 0;

    sf::Clock timer;

    auto lastTime   = timer.getElapsedTime();
    auto tickLag    = sf::Time::Zero;

    while (m_window.isOpen())
    {
        auto& state         = currentState();
        auto currentTime    = timer.getElapsedTime();
        auto elapsed        = currentTime - lastTime;
        lastTime            = currentTime;
        tickLag             += elapsed;

        state.handleInput();

        while (tickLag >= MS_PER_TICK)
        {
            tickCount++;
            state.fixedUpdate (elapsed.asSeconds());
            tickLag -= MS_PER_TICK;
        }
        state.update (elapsed.asSeconds());

        m_window.clear();
        currentState().draw (m_window);
        m_window.display();
        handleEvents();
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
