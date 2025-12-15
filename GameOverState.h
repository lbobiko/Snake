#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#pragma once
#include "IGameState.h"

class GameOverState : public IGameState {
public:
    void tick(GraSnake& game) override;
};
#endif // GAMEOVERSTATE_H
