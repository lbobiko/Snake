#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include "GraSnake.h"

void printBoard(const GraSnake& game) {
    std::cout << "Score: " << game.getScore() << "\n";
    const Board& board = game.getBoard();
    const Snake& snake = game.getSnake();
    const Point& apple = game.getApple();

    int w = board.width();
    int h = board.height();

    std::vector<std::string> grid(h, std::string(w, '.'));

    // wąż
    const auto& segs = snake.segments();
    bool first = true;
    for (const auto& p : segs) {
        if (p.x < 0 || p.x >= w || p.y < 0 || p.y >= h) continue;
        if (first) {
            grid[p.y][p.x] = 'O'; // głowa
            first = false;
        } else {
            grid[p.y][p.x] = 'o'; // ciało
        }
    }

    // jabłko
    if (apple.x >= 0 && apple.x < w && apple.y >= 0 && apple.y < h) {
        grid[apple.y][apple.x] = '*';
    }

    // rysuje na ekran kropki
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            std::cout << grid[y][x];
        }
        std::cout << '\n';
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    GraSnake game(20, 10);

    for (int i = 0; i < 1000; ++i) {
        game.tick();
        std::cout << "Tick " << i << "\n";
        printBoard(game);

        if (game.isPaused()) {
            std::cout << "== PAUZA ==\n";
        }
        if (game.isInGameOver()) {
            std::cout << "GAME OVER! (r = restart, q = wyjscie)\n";
        }

        std::cout << "[ENTER]=dalej, p=pauza/wznow, r=restart, q=koniec > ";
        std::string cmd;
        std::getline(std::cin, cmd);

        if (cmd == "w" || cmd == "W") game.changeDirection(Direction::Up);
        if (cmd == "s" || cmd == "S") game.changeDirection(Direction::Down);
        if (cmd == "a" || cmd == "A") game.changeDirection(Direction::Left);
        if (cmd == "d" || cmd == "D") game.changeDirection(Direction::Right);

        if (cmd == "q") break;

        if (cmd == "r" || cmd == "R") {
            game.newGame();
            continue; // ważne
        }

        if (cmd == "p" || cmd == "P") {
            if (game.isPaused()) game.setStateRunning();
            else game.setStatePaused();
        }

        std::cout << "------------------------\n";
    }

    std::cout << "Koniec testu.\n";
    return 0;
}
