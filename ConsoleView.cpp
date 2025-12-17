#include "ConsoleView.h"
#include "GraSnake.h"
#include <iostream>
#include <vector>
#include <string>

void ConsoleView::onGameUpdated(const GraSnake& game) {
    const Board& board = game.getBoard();
    const Snake& snake = game.getSnake();
    const Point& apple = game.getApple();

    int w = board.width();
    int h = board.height();

    std::vector<std::string> grid(h, std::string(w, '.'));

    // wąż
    bool first = true;
    for (const auto& p : snake.segments()) {
        if (first) {
            grid[p.y][p.x] = 'O';
            first = false;
        } else {
            grid[p.y][p.x] = 'o';
        }
    }

    // jabłko
    grid[apple.y][apple.x] = '*';

    std::cout << "Score: " << game.getScore() << "\n";
    for (const auto& row : grid) {
        std::cout << row << "\n";
    }

    if (game.isPaused()) {
        std::cout << "== PAUZA ==\n";
    }
    if (game.isInGameOver()) {
        std::cout << "GAME OVER! (r = restart, q = wyjscie)\n";
    }
}
