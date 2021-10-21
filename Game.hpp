//
// Created by gicaCean on 9/13/2021.
//

#ifndef PONGLION_GAME_HPP
#define PONGLION_GAME_HPP

#include "Ball.hpp"
#include "Paddle.hpp"
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void run();

public:
    static constexpr uint16_t WIDTH  = 800;
    static constexpr uint16_t HEIGHT = 600;

private:
    void handleInputs();
    void handleEvents();
    void update(sf::Time dTime);
    void render();

private:
    sf::RenderWindow _window;
    sf::Event _event{};

    Ball _ball;
    Paddle _paddle;
    Paddle _botPaddle;

    static constexpr uint8_t FRAME_LIMIT = 60;
};


#endif// PONGLION_GAME_HPP