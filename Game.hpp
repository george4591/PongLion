//
// Created by gicaCean on 9/13/2021.
//

#ifndef PONGLION_GAME_HPP
#define PONGLION_GAME_HPP

#include "Paddle.hpp"
#include "Ball.hpp"
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void run();

public:
    static constexpr unsigned int width  = 800;
    static constexpr unsigned int height = 600;

private:
    constexpr void handleInputs();
    void handleEvents();
    void update(sf::Time dTime);
    void render();

private:
    sf::RenderWindow _window;
    sf::Event _event;

    Ball _ball;
    Paddle _paddle;
    Paddle _botPaddle;

    static constexpr float _paddlePosX = 12.5f;
    static constexpr float _paddlePosY = static_cast<float>(height) / 2 + 50.f;
};


#endif// PONGLION_GAME_HPP