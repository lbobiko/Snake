#ifndef GRASNAKE_H
#define GRASNAKE_H
#pragma once
#include "Board.h"
#include "Snake.h"

class GraSnake {
public:
    GraSnake(int width, int height);

    void tick();        // jedna „klatka” gry (na razie tylko ruch)
    void changeDirection(Direction d);

private:
    Board board;
    Snake snake;
    Direction currentDir;
};

#endif // GRASNAKE_H
