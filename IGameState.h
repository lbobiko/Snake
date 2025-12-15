#ifndef IGAMESTATE_H
#define IGAMESTATE_H

#pragma once

class GraSnake;

class IGameState {
public:
    virtual ~IGameState() = default;

    virtual void tick(GraSnake& game) = 0;
};

#endif // IGAMESTATE_H
