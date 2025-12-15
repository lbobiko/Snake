#include "Board.h"

Board::Board(int width, int height)
    : m_width(width), m_height(height)
{
}

bool Board::isInside(const Point& p) const {
    return p.x >= 0 && p.x < m_width &&
           p.y >= 0 && p.y < m_height;
}

int Board::width() const  {
    return m_width;
}
int Board::height() const {
    return m_height;
}
