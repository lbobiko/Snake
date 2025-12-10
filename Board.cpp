#include "Board.h"

bool Board::isInside(const Point& p) const {
    return p.x >= 0 && p.x < width &&
           p.y >= 0 && p.y < height;
}
