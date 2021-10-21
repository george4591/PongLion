//
// Created by gicaCean on 9/14/2021.
//

#ifndef PONGLION_PADDLE_HPP
#define PONGLION_PADDLE_HPP
#include <SFML/Graphics/RectangleShape.hpp>
#include <cstdint>

class Paddle : public sf::RectangleShape
{
public:
    explicit Paddle(sf::Vector2f pos);

    void move(int y);

public:
    static constexpr uint16_t width   = 8;
    static constexpr uint16_t height  = 75;
    static constexpr float STARTING_X = 12.5f;
    static constexpr float STARTING_Y = 350.f;

private:
    constexpr bool isColliding(unsigned int y) const;
};


#endif// PONGLION_PADDLE_HPP