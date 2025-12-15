#ifndef PAUSEDSTATE_H
#define PAUSEDSTATE_H
#pragma once
#include "IGameState.h"

class PausedState : public IGameState {
public:
    void tick(GraSnake& game) override;
};

#endif // PAUSEDSTATE_H
