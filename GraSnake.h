#pragma once
#include <memory>
#include "Board.h"
#include "Snake.h"
#include "Direction.h"
#include <vector>
#include "IGameObserver.h"

class IGameState;

class GraSnake {
public:
    GraSnake(int width, int height);
    ~GraSnake();

    void tick();   // deleguje do stanu

    // gettery
    const Board& getBoard() const;
    const Snake& getSnake() const;
    const Point& getApple() const;
    Direction getDirection() const;
    int getScore() const;
    bool isInGameOver() const;
    void changeDirection(Direction d);

    // metody używane przez stany
    void moveSnake(bool grow);
    void spawnApple();
    void setStateGameOver();
    void setStateRunning();
    void setStatePaused();
    bool isPaused() const;
    void addScore(int delta);
    void newGame();

    // Observer
    void attachObserver(IGameObserver* obs);
    void detachObserver(IGameObserver* obs);

private:
    Board board;
    Snake snake;
    Direction currentDir;
    Point apple;
    int score;

    std::unique_ptr<IGameState> state;

    std::vector<IGameObserver*> observers;
    void notifyObservers();
};
