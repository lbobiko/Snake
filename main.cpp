#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "GraSnake.h"
#include "ConsoleView.h"

enum class LoopAction {
    Continue,
    Restart,
    Quit
};

static LoopAction handleCommand(GraSnake& game, const std::string& cmd) {
    if (cmd == "q" || cmd == "Q") return LoopAction::Quit;
    if (cmd == "r" || cmd == "R") return LoopAction::Restart;

    if (cmd == "p" || cmd == "P") {
        if (game.isPaused()) game.setStateRunning();
        else game.setStatePaused();
        return LoopAction::Continue;
    }

    // Sterowanie (WASD) – ignoruje w pauzie i po game over
    if (!game.isPaused() && !game.isInGameOver()) {
        if (cmd == "w" || cmd == "W") game.changeDirection(Direction::Up);
        else if (cmd == "s" || cmd == "S") game.changeDirection(Direction::Down);
        else if (cmd == "a" || cmd == "A") game.changeDirection(Direction::Left);
        else if (cmd == "d" || cmd == "D") game.changeDirection(Direction::Right);
    }

    return LoopAction::Continue;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    GraSnake game(20, 10);
    ConsoleView view;
    game.attachObserver(&view);

    for (int tick = 0; tick < 1000000; ++tick) {
        game.tick();

        std::cout << "Tick " << tick << "\n";
        std::cout << "[ENTER]=dalej, WASD=sterowanie, p=pauza, r=restart, q=koniec > ";

        std::string cmd;
        std::getline(std::cin, cmd);

        LoopAction action = handleCommand(game, cmd);

        if (action == LoopAction::Quit) break;
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
