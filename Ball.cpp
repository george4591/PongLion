//
// Created by gicaCean on 9/14/2021.
//

#include "Ball.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <numbers>
#include <random>
//#include <spdlog/spdlog.h>

Ball::Ball(sf::Vector2f pos)
{
    setPosition(pos.x, pos.y);
    setRadius(_radius);
}

bool Ball::isCollidingWall() const { return getPosition().y + _diameter >= 600 || getPosition().y < 0; }
bool Ball::isOutOfBounds() const { return getPosition().x + dx <= 0 || getPosition().x + dx >= 800; }
bool Ball::isCollidingPad(const sf::Vector2f& pad, const sf::Vector2f& bot) const
{
    return (getPosition().x + dx <= pad.x || getPosition().x + _diameter + dx >= bot.x)
           && (getPosition().y >= pad.y && getPosition().y <= pad.y + 75);
}


void Ball::launchBall()
{
    using randomGenerator = std::mt19937;
    std::random_device rd;
    randomGenerator gen(rd());

    std::uniform_int_distribution dir(-1, 1);
    std::uniform_real_distribution<float> ang(0, 60);

    float direction = dir(gen);

    auto toRad  = [&ang, &gen]() { return ang(gen) * std::numbers::pi_v<float> / 180.0f; };
    float angle = toRad();

    dx = direction * speed * std::cosf(angle);
    dy = speed * std::sinf(angle);

    status = Status::LAUNCHED;
}

void Ball::checkCollisions(const sf::Vector2f& pad, const sf::Vector2f& bot)
{
    if (isCollidingWall()) { dy *= -1; }
    if (isCollidingPad(pad, bot)) {
        dx *= -1;
    } else {
        if (isOutOfBounds()) {
            setPosition(STARTING_X, STARTING_Y);
            status = Status::NOT_LAUNCHED;
        }
    }
}

void Ball::move(const sf::Vector2f& pad, const sf::Vector2f& bot)
{
    using kb = sf::Keyboard;
    if (kb::isKeyPressed(kb::Space) && status == Status::NOT_LAUNCHED) { launchBall(); }

    if (status == Status::LAUNCHED) {
        checkCollisions(pad, bot);
        setPosition(getPosition().x + dx, getPosition().y + dy);
    }
}