#include <QCoreApplication>
#include <iostream>
#include <thread>
#include <chrono>
#include "GraSnake.h"

int main() {
    GraSnake game(20, 20);

    for (int i = 0; i < 10; ++i) {
        game.tick();
        std::cout << "Tick " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    std::cout << "Koniec testu.\n";
    return 0;
}
