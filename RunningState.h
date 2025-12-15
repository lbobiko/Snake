#ifndef RUNNINGSTATE_H
#define RUNNINGSTATE_H
#pragma once
#include "IGameState.h"

class RunningState : public IGameState {
public:
    void tick(GraSnake& game) override;
};

#endif // RUNNINGSTATE_H
