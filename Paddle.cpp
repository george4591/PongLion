//
// Created by gicaCean on 9/14/2021.
//

#include "Paddle.hpp"
Paddle::Paddle(sf::Vector2f pos)
{
    setSize({ width, height });
    setPosition(pos.x, pos.y);
}
void Paddle::move(sf::Vector2i pos)
{
    if (!isColliding(pos.y)) { setPosition(static_cast<float>(pos.x), static_cast<float>(pos.y)); }
}
constexpr bool Paddle::isColliding(unsigned int y) const { return y + height >= 585 || y - 0.125 * height < 0; }