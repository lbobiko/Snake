#include "GraSnake.h"

GraSnake::GraSnake(int width, int height)
    : board(width, height), snake(), currentDir(Direction::Right)
{
}

void GraSnake::tick() {
    snake.move(currentDir, false);
}

void GraSnake::changeDirection(Direction d) {
    currentDir = d;
}
