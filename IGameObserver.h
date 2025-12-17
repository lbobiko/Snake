#ifndef IGAMEOBSERVER_H
#define IGAMEOBSERVER_H
#pragma once

class GraSnake;

class IGameObserver {
public:
    virtual ~IGameObserver() = default;

    virtual void onGameUpdated(const GraSnake& game) = 0;
};

#endif // IGAMEOBSERVER_H
