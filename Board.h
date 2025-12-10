#ifndef BOARD_H
#define BOARD_H
#pragma once
#include "Point.h"

class Board {
public:
    Board(int w, int h) : width(w), height(h) {}
    bool isInside(const Point& p) const;

private:
    int width;
    int height;
};

#endif // BOARD_H
