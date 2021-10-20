//
// Created by gicaCean on 9/13/2021.
//

#include "Game.hpp"
#include "spdlog/spdlog.h"

Game::Game()
  : _paddle({ _paddlePosX, _paddlePosY }), _botPaddle({ width - _paddlePosX - Paddle::width, _paddlePosY }),
    _ball({ 300, 300 })
{
    _window.create(sf::VideoMode(width, height), "Pongu\'");
    _window.setFramerateLimit(60);
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

constexpr void Game::handleInputs()
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
        _paddle.move({ static_cast<int>(_paddlePosX), sf::Mouse::getPosition(_window).y });
        _botPaddle.move({ static_cast<int>(_botPaddle.getPosition().x), sf::Mouse::getPosition(_window).y });
    }
}

void Game::handleEvents()
{
    while (_window.pollEvent(_event)) {
        switch (_event.type) {
        case sf::Event::Closed:
            _window.close();
            break;
        case sf::Event::MouseMoved:
        case sf::Event::KeyPressed:
            handleInputs();
            break;
        case sf::Event::KeyReleased:
        case sf::Event::TextEntered:
            break;
        case sf::Event::MouseButtonPressed:
            break;
        case sf::Event::MouseButtonReleased:
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