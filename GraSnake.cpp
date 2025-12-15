#include "GraSnake.h"
#include "IGameState.h"
#include "RunningState.h"
#include "GameOverState.h"
#include "PausedState.h"
#include <cstdlib>


static bool isOpposite(Direction a, Direction b) {
    return (a == Direction::Up    && b == Direction::Down) ||
           (a == Direction::Down  && b == Direction::Up)   ||
           (a == Direction::Left  && b == Direction::Right)||
           (a == Direction::Right && b == Direction::Left);
}

GraSnake::GraSnake(int width, int height)
    : board(width, height), snake(),
    currentDir(Direction::Right), score(0)
{
    spawnApple();
    state = std::make_unique<RunningState>();
}

GraSnake::~GraSnake() = default;

void GraSnake::tick() {
    state->tick(*this);
}

// ===== gettery =====

const Board& GraSnake::getBoard() const { return board; }
const Snake& GraSnake::getSnake() const { return snake; }
const Point& GraSnake::getApple() const { return apple; }
Direction GraSnake::getDirection() const { return currentDir; }

// ===== logika używana przez stany =====

void GraSnake::moveSnake(bool grow) {
    snake.move(currentDir, grow);
}

void GraSnake::spawnApple() {
    int w = board.width();
    int h = board.height();

    while (true) {
        Point p{ std::rand() % w, std::rand() % h };
        if (!snake.collidesWith(p)) {
            apple = p;
            break;
        }
    }
}

void GraSnake::setStateGameOver() {
    state = std::make_unique<GameOverState>();
}

void GraSnake::setStateRunning() {
    state = std::make_unique<RunningState>();
}

void GraSnake::setStatePaused() {
    state = std::make_unique<PausedState>();
}

bool GraSnake::isPaused() const {
    return dynamic_cast<PausedState*>(state.get()) != nullptr;
}

int GraSnake::getScore() const {
    return score;
}

void GraSnake::changeDirection(Direction d) {
    // w GameOver nie ma sensu zmieniać kierunku
    if (isInGameOver()) {
        return;
    }

    // blokada zawracania o 180°
    if (isOpposite(currentDir, d)) {
        return;
    }

    currentDir = d;
}

void GraSnake::addScore(int delta) {
    score += delta;
}


void GraSnake::newGame() {
    score = 0;
    currentDir = Direction::Right;

    // reset węża na środek
    Point start{ board.width() / 2, board.height() / 2 };
    snake.resetTo(start);

    spawnApple();

    // WAŻNE: wróć do RunningState
    state = std::make_unique<RunningState>();
}

bool GraSnake::isInGameOver() const {
    return dynamic_cast<GameOverState*>(state.get()) != nullptr;
}
