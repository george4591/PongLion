//
// Created by gicaCean on 9/14/2021.
//

#ifndef PONGLION_BALL_HPP
#define PONGLION_BALL_HPP
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Time.hpp>

class Ball : public sf::CircleShape
{
public:
    Ball(sf::Vector2f pos);
    void move(const sf::Vector2f& pad, const sf::Vector2f& bot);
    void launchBall();

public:
    static constexpr int16_t STARTING_X = 300;
    static constexpr int16_t STARTING_Y = 300;

private:
    bool isCollidingWall() const;
    bool isCollidingPad(const sf::Vector2f& pad, const sf::Vector2f& bot) const;
    bool isOutOfBounds() const;

    void checkCollisions(const sf::Vector2f& pad, const sf::Vector2f& bot);

private:
    static constexpr float _radius   = 12.5f;
    static constexpr float _diameter = 2 * _radius;

    float speed = 6.30f;
    float dx;
    float dy;

    enum class Status { NOT_LAUNCHED, LAUNCHED };
    Status status = Status::NOT_LAUNCHED;
};


#endif// PONGLION_BALL_HPP