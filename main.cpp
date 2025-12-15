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

enum class LoopAction {
    Continue,
    Restart,
    Quit
};

static LoopAction handleCommand(GraSnake& game, const std::string& cmd) {
    if (cmd == "q" || cmd == "Q") {
        return LoopAction::Quit;
    }

    if (cmd == "r" || cmd == "R") {
        return LoopAction::Restart;
    }

    if (cmd == "p" || cmd == "P") {
        if (game.isPaused()) game.setStateRunning();
        else game.setStatePaused();
        return LoopAction::Continue;
    }

    // Sterowanie (WASD)
    if (!game.isPaused() && !game.isInGameOver()) {
        if (cmd == "w" || cmd == "W") game.changeDirection(Direction::Up);
        else if (cmd == "s" || cmd == "S") game.changeDirection(Direction::Down);
        else if (cmd == "a" || cmd == "A") game.changeDirection(Direction::Left);
        else if (cmd == "d" || cmd == "D") game.changeDirection(Direction::Right);
    }

    return LoopAction::Continue;
}

static void printStatus(const GraSnake& game) {
    if (game.isPaused()) {
        std::cout << "== PAUZA ==\n";
    }
    if (game.isInGameOver()) {
        std::cout << "GAME OVER! (r = restart, q = wyjscie)\n";
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    GraSnake game(20, 10);

    for (int tick = 0; tick < 1000000; ++tick) {
        game.tick();

        std::cout << "Tick " << tick << "\n";
        printBoard(game);
        printStatus(game);

        std::cout << "[ENTER]=dalej, WASD=sterowanie, p=pauza, r=restart, q=koniec > ";
        std::string cmd;
        std::getline(std::cin, cmd);

        LoopAction action = handleCommand(game, cmd);

        if (action == LoopAction::Quit) {
            break;
        }
        if (action == LoopAction::Restart) {
            game.newGame();
            std::cout << "------------------------\n";
            continue;
        }

        std::cout << "------------------------\n";
    }

    std::cout << "Koniec testu.\n";
    return 0;
}
