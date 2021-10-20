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

constexpr float toRad(float angle) { return angle * std::numbers::pi_v<float> / 180.0f; }

void Ball::launchBall()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution dir(-1, 1);
    std::uniform_real_distribution<float> ang(0, 60);

    float direction = dir(gen);
    float angle     = toRad(ang(gen));

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
            setPosition(400, 300);
            status = Status::NOT_LAUNCHED;
        }
    }
}

void Ball::move(const sf::Vector2f& pad, const sf::Vector2f& bot)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && status == Status::NOT_LAUNCHED) { launchBall(); }

    if (status == Status::LAUNCHED) {
        checkCollisions(pad, bot);
        setPosition(getPosition().x + dx, getPosition().y + dy);
    }
}