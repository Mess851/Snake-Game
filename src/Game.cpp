#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

#include "Game.hpp"

Game::Game() : m_context(std::make_shared<Context>())
{
    m_context->m_window->create(sf::VideoMode(), "SFML works!", sf::Style::Close);
}

Game::~Game()
{
}

void Game::Run()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (m_context->m_window->isOpen())
    {
        

        sf::Event event;
        while (m_context->m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_context->m_window->close();
        }

        m_context->m_window->clear();
        m_context->m_window->draw(shape);
        m_context->m_window->display();
        
    }
    
}