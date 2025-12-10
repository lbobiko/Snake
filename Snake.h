#ifndef SNAKE_H
#define SNAKE_H
#pragma once
#include <deque>
#include "Point.h"
#include "Direction.h"

class Snake {

public:
    Snake();

    const Point& head() const;
    void move(Direction d, bool grow);
    bool collidesWith(const Point& p) const;
    bool selfCollision() const;

private:
    std::deque<Point> segments;
};

#endif // SNAKE_H
