#pragma once
#include <deque>
#include "Point.h"
#include "Direction.h"

class Snake {
public:
    Snake();

    const Point& head() const;
    void move(Direction direction, bool grow);
    bool collidesWith(const Point& p) const;
    bool selfCollision() const;
    void resetTo(const Point& headPos);

    const std::deque<Point>& segments() const;

private:
    std::deque<Point> m_segments;
};
