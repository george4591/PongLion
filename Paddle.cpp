//
// Created by gicaCean on 9/14/2021.
//

#include "Paddle.hpp"
Paddle::Paddle(sf::Vector2f pos)
{
    setSize({ width, height });
    setPosition(pos.x, pos.y);
}
void Paddle::move(int y)
{
    // TODO: make this work for the bot without having 2 different calls(if it works?)
    if (!isColliding(y)) {
        if (getPosition().x == STARTING_X) {
            setPosition(STARTING_X, static_cast<float>(y));
        } else {
            setPosition(getPosition().x, static_cast<float>(y));
        }
    }
}

// FIXME: remove the magic numbers
constexpr bool Paddle::isColliding(unsigned int y) const { return y + height >= 585 || y - 0.125 * height < 0; }