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

    void move(sf::Vector2i pos);

public:
    static constexpr uint16_t width  = 8;
    static constexpr uint16_t height = 75;

private:
    constexpr bool isColliding(unsigned int y) const;
};


#endif// PONGLION_PADDLE_HPP