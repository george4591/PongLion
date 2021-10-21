//
// Created by gicaCean on 9/13/2021.
//

#include "Game.hpp"
#include "spdlog/spdlog.h"

Game::Game()
  : _paddle({ Paddle::STARTING_X, Paddle::STARTING_Y }),
    _botPaddle({ WIDTH - Paddle::STARTING_X - Paddle::width, Paddle::STARTING_Y }),
    _ball({ Ball::STARTING_X, Ball::STARTING_Y })
{
    _window.create(sf::VideoMode(WIDTH, HEIGHT), "Pongu\'");
    _window.setFramerateLimit(FRAME_LIMIT);
    _window.setMouseCursorVisible(false);
    _window.setMouseCursorGrabbed(true);
}

void Game::run()
{
    sf::Clock dClock;
    sf::Time dTime;
    while (_window.isOpen()) {
        dTime = dClock.restart();
        handleEvents();
        update(dTime);
        render();
    }
}

void Game::handleInputs()
{
    if (_event.type == sf::Event::KeyPressed) {
        switch (_event.key.code) {
        case sf::Keyboard::Escape:
            _window.close();
        case sf::Keyboard::P:
            spdlog::warn("Game Paused");
            break;
        case sf::Keyboard::Space:
            _ball.launchBall();
            break;
        case sf::Keyboard::Left:
            break;
        }
    } else if (_event.type == sf::Event::MouseMoved) {
        const auto mousePos = sf::Mouse::getPosition(_window);
        _paddle.move(mousePos.y);
        _botPaddle.move(mousePos.y);
    }
}

void Game::handleEvents()
{
    using ev = sf::Event;
    while (_window.pollEvent(_event)) {
        switch (_event.type) {
        case ev::Closed:
            _window.close();
            break;
        case ev::MouseMoved:
        case ev::KeyPressed:
            handleInputs();
            break;
        case ev::KeyReleased:
        case ev::TextEntered:
            break;
        case ev::MouseButtonPressed:
            break;
        case ev::MouseButtonReleased:
            break;
        default:
            // spdlog::info("Unhandled event");
            break;
        }
    }
}
void Game::update(sf::Time dTime) { _ball.move(_paddle.getPosition(), _botPaddle.getPosition()); }
void Game::render()
{
    _window.clear(sf::Color::Black);
    _window.draw(_paddle);
    _window.draw(_botPaddle);
    _window.draw(_ball);
    _window.display();
}