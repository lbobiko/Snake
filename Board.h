#pragma once
#include "Point.h"

class Board {
public:
    Board(int width, int height);

    bool isInside(const Point& p) const;
    int width() const;
    int height() const;

private:
    int m_width;
    int m_height;
};
