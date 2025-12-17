#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H
#pragma once
#include "IGameObserver.h"

class ConsoleView : public IGameObserver {
public:
    void onGameUpdated(const GraSnake& game) override;
};

#endif // CONSOLEVIEW_H
